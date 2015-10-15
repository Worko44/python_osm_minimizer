#include "osmMinimizer.h"

int verif_end(char *line)
{
  int i = my_strlen(line);

  if (i > 2)
    {
      if (line[i - 2] == '/')
	{
	  return (END_TYPE_LINE);
	}
    }
  return (NO_END_TYPE_LINE);
}

int write_line_file(int fd, char *line)
{
  int ret = 0;
  char end_line = '\n';
  ret = write(fd, line, my_strlen(line));
  if (ret < 0)
    return (ret);
  ret = write(fd, &end_line, 1);
  return (ret);
}

t_tag	*recup_struct_tag(char *str_tag)
{
  t_tag	*tag;
  t_info *info;

  if ((info = recup_info(str_tag)) == NULL)
    return (NULL);
  if ((tag = malloc(sizeof(*tag))) == NULL)
    {
      printf("Erreur lors d'un malloc\n");
      return (NULL);
    }
  tag->key = recup_info_type(info, "k");
  tag->value = recup_info_type(info, "v");
  free_info(info);
  return (tag);
}

void	free_tag(t_tag *tag)
{
  if (tag != NULL)
    {
      free(tag->key);
      free(tag->value);
      free(tag);
    }
}

char **verif_tag(char **tab, t_conf *conf)
{
  char **new_tab = NULL;
  char	*name = NULL;
  int i = 0;
  int n = 0;
  int find_place = 0;

  if (tab == NULL)
    return tab;
  while (tab[i] != NULL)
    {
      type_osm type = recup_type(tab[i]);
      if (type == TYPE_TAG)
	{
	  t_tag *tag = recup_struct_tag(tab[i]);
	  
	  if (my_strcmp(tag->key, "name") == 0)
	    name = my_strdup(tab[i]);
	  t_conf *tmp = conf;
	  while (tmp != NULL)
	    {
	      if (my_strcmp(tag->key, tmp->key) == 0)
		{
		  n = 0;
		  int save = 0;
		  while (tmp->value[n] != NULL)
		    {
		      if (my_strcmp(tag->value, tmp->value[n]) == 0)
			{
			  
			  save = 1;
			  break;
			}
		      n++;
		    }
		  if (save == 1)
		    {
		      if (my_strcmp(tag->key, "place") == 0)
			find_place = 1;
		      new_tab = add_in_tab(new_tab, tab[i]);
		    }
		  break;
		}
	      tmp = tmp->next;
	    }
	  free_tag(tag);
	}
      i++;
    }
  free_tab(tab);
  if (name != NULL)
    {
      if (find_place != 0)
	new_tab = add_in_tab(new_tab, name);
      free(name);
    }
  return (new_tab);
}

void	write_good_node(char *node)
{
  t_info *info;
  char	*id;
  char *name_file;
  int size;
  char *path = "./tmp/good_node/";
  int fd;

  if ((info = recup_info(node)) == NULL)
    return ;
  id = recup_info_type(info, "ref");
  size = my_strlen(id) + my_strlen(path) + 2;
  if ((name_file = malloc(size * sizeof(*name_file))) == NULL)
    return ;
  int m = 0;
  name_file = my_strcpy(name_file, path);
  int l = my_strlen(path);
  while (id[m] != 0)
    {
      name_file[m + l] = id[m];
      m++;
    }
  name_file[m + l] = 0;
  if ((fd = open(name_file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
    {
      printf("Erreur dans la creation du fichier de la node\n");
      return ;
    }
  free(name_file);
  close(fd);
  free(id);
  free_info(info);
}

void	write_data_way(int fd_final_way, char **tag_nd, char **tag_node, char *node, char *end)
{
  if (tag_node != NULL)
    {
      int i = 0;

      if (write_line_file(fd_final_way, node) < 0)
	{
	  printf("Erreur dans l'écriture dans le fichier\n");
	  return ;
	}
      if (tag_nd != NULL)
	{
	  while (tag_nd[i] != NULL)
	    {
	      write_good_node(tag_nd[i]);
	      if (write_line_file(fd_final_way, tag_nd[i]) < 0)
		{
		  printf("Erreur dans l'écriture dans le fichier\n");
		  return ;
		}
	      i++;
	    }
	}
      i = 0;
      while (tag_node[i] != NULL)
	{
	  if (write_line_file(fd_final_way, tag_node[i]) < 0)
	    {
	      printf("Erreur dans l'écriture dans le fichier\n");
	      return ;
	    }
	  i++;
	}
      if (write_line_file(fd_final_way, end) < 0)
	{
	  printf("Erreur dans l'écriture dans le fichier\n");
	  return ;
	}
    }
}

void	write_data_node(int fd_write_node, int fd_final_node, char **tag_node, char *node, char *end)
{
  if (tag_node == NULL)
    {
      char *new_node;
      int size = my_strlen(node);
      if ((new_node = malloc((size + 2) * sizeof(*new_node))) == NULL)
	{
	  printf("Erreur malloc\n");
	  return ;
	}
      new_node = my_strcpy(new_node, node);
      new_node[size - 1] = '/';
      new_node[size] = '>';
      new_node[size + 1] = 0;
      if (write_line_file(fd_write_node, new_node) < 0)
	{
	  printf("Erreur dans l'écriture dans le fichier\n");
	  return ;
	}
      free(new_node);
    }
  else
    {
      int i = 0;

      if (write_line_file(fd_final_node, node) < 0)
	{
	  printf("Erreur dans l'écriture dans le fichier\n");
	  return ;
	}
      while (tag_node[i] != NULL)
	{
	  if (write_line_file(fd_final_node, tag_node[i]) < 0)
	    {
	      printf("Erreur dans l'écriture dans le fichier\n");
	      return ;
	    }
	  i++;
	}
      if (write_line_file(fd_final_node, end) < 0)
	{
	  printf("Erreur dans l'écriture dans le fichier\n");
	  return ;
	}
      
      (void)fd_final_node;
    }
}

void rewrite_good_node(char *path_write_node, int fd_final_node, unsigned long long nb_node)
{
  int fd_write_node;
  char *buff;
  //  char buff2[1024];
  unsigned long long nb = 0;
  unsigned long long one_pour = nb_node / 100;
  unsigned int total_pour = 0;
  t_info *info;
  char	*id;
  int size;
  char *path = "./tmp/good_node/";
  char *name_file;
  int fd;

  if ((fd_write_node = open(path_write_node, O_RDONLY)) < 0)
    {
      printf("Erreur dans la creation du fichier tmp\n");
      return ;
    }
  while ((buff = get_next_line(fd_write_node)) != NULL)
    {
      if (buff[0] == 0)
	{
	  free(buff);
	  continue;
	}
      nb++;
      if (nb == one_pour)
	{
	  total_pour += 1;
	  printf("-> %d%%\n", total_pour); 
	  nb = 0;
	}
      if ((info = recup_info(buff)) == NULL)
	{
	  free(buff);
	  printf("Erreur pour la recup d'info\n");
	  continue;
	}
      id = recup_info_type(info, "id");
      free_info(info);
      size = my_strlen(id) + my_strlen(path) + 2;
      if ((name_file = malloc(size * sizeof(*name_file))) == NULL)
	{
	  printf("Erreur malloc\n");
	  return ;
	}
      int m = 0;
      name_file = my_strcpy(name_file, path);
      int l = my_strlen(path);
      while (id[m] != 0)
	{
	  name_file[m + l] = id[m];
	  m++;
	}
      name_file[m + l] = 0;
      if ((fd = open(name_file, O_RDONLY)) >= 0)
	{
	  if (write_line_file(fd_final_node, buff) < 0)
	    {
	      printf("Erreur dans l'écriture dans le fichier\n");
	      return ;
	    }
	  close(fd);
	}
      free(name_file);
      free(id);      
      free(buff);
    }
  close(fd_write_node);
  
}


void aff_conf(t_conf *conf)
{
  while (conf != NULL)
    {
      printf("Key : %s\n", conf->key);
      int i = 0;
      while (conf->value[i] != NULL)
	{
	  printf("Value : %s\n", conf->value[i]);
	  i++;
	}
      conf = conf->next;
    }
}

void read_node(int fd, char *path_config, char *path_final, char *path_final_map)
{
  char *buff;
  type_osm base = NO_TYPE;
  type_osm groupe = NO_TYPE;
  char *line_clean;
  char *xml_version = NULL;
  char *bounds = NULL;
  char *osm_version = NULL;
  char *node = NULL;
  char **tag_nd = NULL;
  char **tag_node = NULL;
  t_conf *conf_test = read_file_conf(path_config);
  int fd_write_node;
  int fd_final_node;
  int fd_final_way;
  int fd_good_node;
  char *path_write_node = "./tmp/node_only.osm";
  char *path_final_node = "./tmp/node_final.osm";
  char *path_final_way = "./tmp/way_final.osm";
  char *path_good_node = "./tmp/good_node.osm";
  unsigned long long nb_node = 0;
  unsigned long long nb_nd = 0;
  unsigned long long nb_good_nd = 0;
  int fd_final;
  unsigned long long nb_line = 0;


  system("rm -rf ./tmp");
  system("mkdir -p ./tmp/good_node");

  if ((fd_final = open(path_final, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
    {
      printf("Erreur dans la creation du fichier final\n");
      return ;
    }

  if ((fd_write_node = open(path_write_node, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
    {
      printf("Erreur dans la creation du fichier tmp\n");
      return ;
    }
  if ((fd_final_node = open(path_final_node, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
    {
      printf("Erreur dans la creation du fichier tmp\n");
      return ;
    }
  if ((fd_final_way = open(path_final_way, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
    {
      printf("Erreur dans la creation du fichier tmp\n");
      return ;
    }
  if ((fd_good_node = open(path_good_node, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
    {
      printf("Erreur dans la creation du fichier tmp\n");
      return ;
    }

  printf("Recuperes les données du fichier\n");
  while ((buff = get_next_line(fd)) != NULL)
    {
      nb_line += 1;
      if ((nb_line % 100000) == 0)
	{
	  printf("line lu : %llu, nb node : %llu, nb good node : %llu\n", nb_line, nb_node, nb_good_nd);
	}
      line_clean = kill_space(buff);
      if (my_strlen(line_clean) != 0)
	{
	  type_osm type = recup_type(line_clean);
	  if (type == TYPE_XML)
	    xml_version = my_strdup(buff);
	  if (type == TYPE_BOUNDS)
	    bounds = my_strdup(buff);
	  if (type == TYPE_OSM)
	    {
	      base = type;
	      osm_version = my_strdup(buff);
	    }
	  if (type == END_OSM)
	    {
	      base = NO_TYPE;
	    }
	  if (type == TYPE_NODE)
	    {
	      //	      printf("%s\n", line_clean);
	      if (base != TYPE_OSM)
		{
		  printf("Erreur node non compris dans l'osm\n");
		  return ;
		}
	      if (verif_end(line_clean) == NO_END_TYPE_LINE)
		{
		  groupe = type;
		  node = my_strdup(line_clean);
		}
	      else
		{
		  nb_node += 1;
		  if (write_line_file(fd_write_node, line_clean) < 0)
		    {
		      printf("Erreur dans l'écriture dans le fichier\n");
		      return ;
		    }
		}
	    }
	  if (type == TYPE_ND)
	    {
	      if (groupe == TYPE_WAY)
		{
		  nb_nd += 1;
		  tag_nd = add_in_tab(tag_nd, line_clean);
		}
	    }
	  if (type == TYPE_TAG)
	    {
	      if (groupe == TYPE_NODE || groupe == TYPE_WAY)
		{
		  tag_node = add_in_tab(tag_node, line_clean);
		}
	    }
	  if (type == END_NODE)
	    {
	      if (groupe != TYPE_NODE)
		{
		  printf("Erreur fin de node alors que node pas ouverte\n");
		  return ;
		}
	      tag_node = verif_tag(tag_node, conf_test);
	      if (tag_node == NULL)
		nb_node += 1;
	      write_data_node(fd_write_node, fd_final_node, tag_node, node, line_clean);
	      tag_node = free_tab(tag_node);
	      free(node);
	      node = NULL;
	      groupe = NO_TYPE;
	    }
	  if (type == TYPE_WAY)
	    {
	      if (base != TYPE_OSM)
		{
		  printf("Erreur way non compris dans l'osm\n");
		  return ;
		}
	      if (verif_end(line_clean) == NO_END_TYPE_LINE)
		{
		  groupe = type;
		  node = my_strdup(line_clean);
		}
	    }
	  if (type == END_WAY)
	    {
	      if (groupe != TYPE_WAY)
		{
		  printf("Erreur fin de way alors que way pas ouverte\n");
		  return ;
		}
	      tag_node = verif_tag(tag_node, conf_test);
	      if (tag_node != NULL)
		nb_good_nd += nb_nd;
	      write_data_way(fd_final_way, tag_nd, tag_node, node, line_clean);
	      tag_node = free_tab(tag_node);
	      tag_nd = free_tab(tag_nd);
	      nb_nd = 0;
	      free(node);
	      node = NULL;
	      groupe = NO_TYPE;
	    }
	  if (type == NO_TYPE)
	    {
	      printf("Type indeterminer\n");
	      return ;
	    }
	}
      free(line_clean);
      free(buff);
    }
  close(fd_write_node);
  close(fd_good_node);
  close(fd_final_way);
  printf("Récupération des bonnes nodes (total %llu sur %llu nodes)\n", nb_good_nd, nb_node);
  rewrite_good_node(path_write_node, fd_final_node, nb_node);
  close(fd_final_node);

  printf("Create file result : %s\n", path_final);
  if (write_line_file(fd_final, xml_version) < 0)
    {
      printf("Erreur dans l'écriture dans le fichier\n");
      return ;
    }
  if (write_line_file(fd_final, osm_version) < 0)
    {
      printf("Erreur dans l'écriture dans le fichier\n");
      return ;
    }
  if (write_line_file(fd_final, bounds) < 0)
    {
      printf("Erreur dans l'écriture dans le fichier\n");
      return ;
    }
    
  if ((fd_final_node = open(path_final_node, O_RDWR)) < 0)
    {
      printf("Erreur dans l'ouverture de final node : %s\n", path_final_node);
      return ;
    }
    while ((buff = get_next_line(fd_final_node)) != NULL)
    {
      if (buff[0] != 0)
	if (write_line_file(fd_final, buff) < 0)
	  {
	    printf("Erreur dans l'écriture dans le fichier\n");
	    return ;
	  }
      free(buff);
    }
  close(fd_final_node);
  if ((fd_final_way = open(path_final_way, O_RDONLY)) < 0)
    {
      printf("Erreur dans l'ouverture du fichier tmp\n");
      return ;
    }
  while ((buff = get_next_line(fd_final_way)) != NULL)
    {
      if (buff[0] != 0)
	if (write_line_file(fd_final, buff) < 0)
	  {
	    printf("Erreur dans l'écriture dans le fichier\n");
	    return ;
	  }
      free(buff);
    }
  close(fd_final_way);
  if (write_line_file(fd_final, "</osm>") < 0)
    {
      printf("Erreur dans l'écriture dans le fichier\n");
      return ;
    }
  close(fd_final);
  free(xml_version);
  free(osm_version);
  free_conf(conf_test);

  char *cmd;
  if ((cmd = malloc(1000 * sizeof(*cmd))) == NULL)
    return ;

  char *first = "cd converter/bin && ./osmosis --rx file=../../";
  cmd = my_strcpy(cmd, first);
  cmd = my_strcat(cmd, path_final);
  cmd = my_strcat(cmd, " --mapfile-writer file=../../");
  cmd = my_strcat(cmd, path_final_map);
  cmd = my_strcat(cmd, " bbox=");
  
  char *bounds_no_space = kill_space(bounds);
  t_info *info = recup_info(bounds_no_space);
  cmd = my_strcat(cmd, recup_info_type(info, "minlat"));
  cmd = my_strcat(cmd, ",");
  cmd = my_strcat(cmd, recup_info_type(info, "minlon"));
  cmd = my_strcat(cmd, ",");
  cmd = my_strcat(cmd, recup_info_type(info, "maxlat"));
  cmd = my_strcat(cmd, ",");
  cmd = my_strcat(cmd, recup_info_type(info, "maxlon"));
  printf("cmd : %s\n", cmd);
  system(cmd);

  char *clear;
  
  printf("Nettoyage\n");
  clear = my_strdup("rm -rf ./tmp/");
  system(clear);
  
  free(clear);
  free(bounds);
  free_info(info);
  free(cmd);
  free(bounds_no_space);
}

int main(int ac, char **av)
{
  
  if (ac == 5)
    {
      int fd;
      
      if ((fd = open(av[1], O_RDONLY)) == -1)
	{
	  printf("Erreur lors de l'ouverture du fichier\n");
	  return (-1);
	}
      read_node(fd, av[2], av[3], av[4]);
    }
  else
    {
      printf("Usage : ./exec file_no_opti.osm file.json name_rslt.osm name_rlst.map\n");
    }
  return (0);
}
