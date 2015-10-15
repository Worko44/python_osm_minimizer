#include "osmMinimizer.h"


t_info	*recup_info(char *line)
{
  t_info *info = NULL;
  t_info *tmp;
  int i = 0;
  int n = 0;

  if (line == NULL)
    return (NULL);
  while (line[i] != ' ' && line[i] != 0)
    i++;
  if (line[i] == 0)
    return (NULL);
  i++;

  while (line[i] != 0 && (line[i] != '>' || (line[i] != '/' && line[i + 1] != '>')))
    {
      if ((tmp = malloc(sizeof(*tmp))) == NULL)
	{
	  printf("Erreur lors d'un malloc\n");
	  return (NULL);
	}
      n = 0;
      while (line[i + n] != '=' && line[i + n] != 0)
	n++;
      if ((tmp->type = malloc((n + 1) * sizeof(*(tmp->type)))) == NULL)
	{
	  printf("Erreur lors d'un malloc\n");
	  return (NULL);
	}
      n = 0;
      while (line[i] != '=' && line[i] != 0)
	{
	  tmp->type[n] = line[i];
	  i++;
	  n++;
	}
      tmp->type[n] = 0;
      i += 2;
      n = 0;
      while (line[i + n] != '"' && line[i + n] != 0)
	n++;
      if ((tmp->value = malloc((n + 1) * sizeof(*(tmp->value)))) == NULL)
	{
	  printf("Erreur lors d'un malloc\n");
	  return (NULL);
	}
      n = 0;
      while (line[i] != '"' && line[i] != 0)
	{
	  tmp->value[n] = line[i];
	  i++;
	  n++;
	}
      tmp->value[n] = 0;
      i++;
      tmp->next = info;
      info = tmp;
      while (line[i] == ' ' && line[i] != 0)
	i++;
      if (line[i] == '>' || (line[i] == '/' && line[i + 1] == '>'))
	break;
    }
  return (info);
}

char	*recup_info_type(t_info *info, char *type)
{
  while (info != NULL)
    {
      if (my_strcmp(info->type, type) == 0)
	return (my_strdup(info->value));
      info = info->next;
    }
  return (NULL);
}

void	free_info(t_info *info)
{
  t_info *next;

  while (info != NULL)
    {
      free(info->type);
      free(info->value);
      next = info->next;
      free(info);
      info = next;
    }
}

