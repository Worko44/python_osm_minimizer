#include "osmMinimizer.h"

t_conf *read_file_conf(char *path)
{
  char *buff;
  char *view;
  int fd;
  t_conf	*conf = NULL;
  t_conf	*tmp;

  if ((fd = open(path, O_RDONLY)) < 0)
    {
      printf("Erreur dans la lecture du fichier de conf\n");
      return NULL;
    }
  int mf = 0;
  while ((buff = get_next_line(fd)) != NULL)
    {
      if (mf == 0)
	{
	  view = &buff[9];
	  int i = 0;
	  int size;
	  while (42)
	    {
	      while (view[i] != '"')
		i++;
	      i++;
	      size = calc_size_value(&view[i]);
	      if ((tmp = malloc(sizeof(*tmp))) == NULL)
		{
		  printf("Erreur malloc\n");
		  return (NULL);
		}
	      tmp->next = conf;
	      if ((tmp->key = malloc((size + 1) * sizeof(*(tmp->key)))) == NULL)
		{
		  printf("Erreur malloc\n");
		  return (NULL);
		}
	      tmp->key = my_strncpy(tmp->key, &view[i], size);
	      tmp->key[size] = 0;
	      tmp->value = NULL;
	      i += size + 1;
	      if (my_strncmp(&view[i], ": [", 2) == 0)
		{
		  i += 3;
		  char *value;
		  
		  while (42)
		    {
		      while (view[i] != '"')
		    i++;
		      i++;
		      size = calc_size_value(&view[i]);
		      if ((value = malloc((size + 1) * sizeof(*value))) == NULL)
			{
			  printf("Erreur malloc\n");
			  return (NULL);
			}
		      value = my_strncpy(value, &view[i], size);
		      value[size] = 0;
		      tmp->value = add_in_tab(tmp->value, value);
		      free(value);
		      i += size + 1;
		      if (view[i] == ']')
			{
			  i += 1;
			  break;
			}
		      else
			i += 2;
		    }
		}
	      conf = tmp;
	      if (view[i] == '}')
		{
		  close(fd);
		  return (conf);
		}
	      else
		i += 2;
	    }
	}
      mf += 1;
      free(buff);
    }
  close(fd);
  return NULL;
}

void free_conf(t_conf *conf)
{
  t_conf *next;

  while (conf != NULL)
    {
      free(conf->key);
      free_tab(conf->value);
      next = conf->next;
      free(conf);
      conf = next;
    }
}

