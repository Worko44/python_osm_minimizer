#include "osmMinimizer.h"

char *recup_bounds(char *file_rslt)
{
  char *buff;
  int fd;
  char *bounds = NULL;
  char *line_clean;

  if ((fd = open(file_rslt, O_RDONLY)) == -1)
    {
      printf("Erreur lors de l'ouverture du fichier\n");
      return (NULL);
    }  
 while ((buff = get_next_line(fd)) != NULL)
   {
      line_clean = kill_space(buff);
      if (my_strlen(line_clean) != 0)
	{
	  type_osm type = recup_type(line_clean);
	  if (type == TYPE_BOUNDS)
	    {
	      bounds = line_clean;
	      free(buff);
	      break;
	    }
	}
      free(line_clean);
      free(buff);
   }
 close(fd);
 return (bounds);
}

int osm_filter(char *file_base, char *file_conf, char *file_rslt, char *file_rslt_map)
{
  t_conf *conf = read_file_conf(file_conf);
  t_conf *tmp;
  char *cmd;
  int i = 0;
  int n = 0;
  char *bounds;

  if ((cmd = malloc(4000 * sizeof(*cmd))) == NULL)
    return (0);
  cmd = my_strcpy(cmd, "osmfilter ");
  cmd = my_strcat(cmd, file_base);
  cmd = my_strcat(cmd, " --keep=\"");
  tmp = conf;
  while (tmp != NULL)
    {
      if (i != 0)
	cmd = my_strcat(cmd, " ");
      cmd = my_strcat(cmd, tmp->key);
      n = 0;
      while (tmp->value[n] != NULL)
	{
	  if (n != 0)
	    cmd = my_strcat(cmd, " ");
	  cmd = my_strcat(cmd, "=");
	  cmd = my_strcat(cmd, tmp->value[n]);
	  n++;
	}
      tmp = tmp->next;
      i++;
    }
  cmd = my_strcat(cmd, "\" -v --drop-relations -o=");
  cmd = my_strcat(cmd, file_rslt);
  system(cmd);
  bounds = recup_bounds(file_rslt);
  free(cmd);

  if ((cmd = malloc(1000 * sizeof(*cmd))) == NULL)
    return -1;

  cmd = my_strcpy(cmd, "cd converter/bin && ./osmosis --rx file=../../");
  cmd = my_strcat(cmd, file_rslt);
  cmd = my_strcat(cmd, " --mapfile-writer file=../../");
  cmd = my_strcat(cmd, file_rslt_map);
  cmd = my_strcat(cmd, " bbox=");
  
  t_info *info = recup_info(bounds);
  cmd = my_strcat(cmd, recup_info_type(info, "minlat"));
  cmd = my_strcat(cmd, ",");
  cmd = my_strcat(cmd, recup_info_type(info, "minlon"));
  cmd = my_strcat(cmd, ",");
  cmd = my_strcat(cmd, recup_info_type(info, "maxlat"));
  cmd = my_strcat(cmd, ",");
  cmd = my_strcat(cmd, recup_info_type(info, "maxlon"));
  printf("cmd : %s\n", cmd);
  system(cmd);
  
  printf("%s\n", cmd);
  free(cmd);
  free_info(info);
  free_conf(conf);
  return (0);
}

int main(int ac, char **av)
{
  
  if (ac == 5)
    {
      return (osm_filter(av[1], av[2], av[3], av[4]));
    }
  else
    {
      printf("Usage : ./exec file_no_opti.osm file.json name_rslt.osm name_rlst.map\n");
    }
  return (0);
}
