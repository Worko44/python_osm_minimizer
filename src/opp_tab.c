#include "osmMinimizer.h"

char **add_in_tab(char **tab, char *add)
{
  char **new_tab = NULL;
  char *new_add;

  if ((new_add = my_strdup(add)) == NULL)
    return (tab);
  if (tab == NULL)
    {
      if ((new_tab = malloc(2 * sizeof(*new_tab))) == NULL)
	{
	  printf("Erreur lors d'un malloc\n");
	  return (NULL);
	}
      new_tab[0] = new_add;
      new_tab[1] = NULL;
    }
  else
    {
      int size = 0;
      int i = 0;
      while (tab[size] != NULL)
	size++;
      size += 2;
      if ((new_tab = malloc(size * sizeof(*new_tab))) == NULL)
	{
	  printf("Erreur lors d'un malloc\n");
	  return (NULL);
	}
      while (tab[i] != NULL)
	{
	  new_tab[i] = tab[i];
	  i++;
	}
      new_tab[i] = new_add;
      new_tab[i + 1] = NULL;
      free(tab);
    }
  return (new_tab);
}

char **free_tab(char **tab)
{
  if (tab != NULL)
    {
      int i = 0;

      while (tab[i] != NULL)
	{
	  free(tab[i]);
	  i++;
	}
      free(tab);
    }
  return (NULL);
}

int	calc_size_value(char *buff)
{
  int i;

  i = 0;
  while (buff[i] != '"' && buff[i] != 0)
    i++;
  return i;
}

