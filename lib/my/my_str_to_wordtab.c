/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/lecuye_j/rendu/Piscine_C_J08/ex_04
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Thu Oct  9 15:11:14 2014 Johan Lecuyer
** Last update Mon Oct 20 16:00:04 2014 Johan Lecuyer
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int	find_alphanummerique(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (0);
  else if (c >= '0' && c <= '9')
    return (0);
  return (-1);
}

int	find_size_word(char *str, int *n)
{
  int	flag_word;
  int	i;
  int	nb;

  i = *n;
  flag_word = 0;
  while (str[i] != 0)
    {
      nb = find_alphanummerique(str[i]);
      if (flag_word == 0 && nb == 0)
	{
	  flag_word = 1;
	  *n = i;
	}
      else if (flag_word == 1 && nb == -1)
	return (i - *n);
      i++;
    }
  if (flag_word == 0)
    return (0);
  else
    return (i - *n);
}

int	recup_str_word(char *str, char **wordtab)
{
  int	i;
  int	nb;
  int	size;
  int	n;

  n = 0;
  i = 0;
  while (42)
    {
      nb = find_size_word(str, &i);
      if (nb == 0)
	{
	  if ((wordtab[n] = malloc((3) * sizeof(*(wordtab[n])))) == NULL)
	    return (-1);
	  wordtab[n][0] = 0;
	  return (0);
	}
      if ((wordtab[n] = malloc((nb + 3) * sizeof(*(wordtab[n])))) == NULL)
	return (-1);
      wordtab[n] = my_strncpy(wordtab[n], &str[i], nb);
      wordtab[n][nb] = 0;
      i += nb;
      n++;
    }
  return (0);
}

int	find_nbr_word(char *str)
{
  int	nb_word;
  int	i;
  int	flag_word;
  int	nb;

  i = 0;
  nb = -1;
  nb_word = 1;
  flag_word = 0;
  while (str[i] != 0)
    {
      nb = find_alphanummerique(str[i]);
      if (flag_word == 0 && nb == 0)
	{
	  nb_word += 1;
	  flag_word = 1;
	}
      else if (flag_word == 1 && nb == -1)
	flag_word = 0;
      i++;
    }
  if (nb == 0)
    nb_word += 1;
  return (nb_word);
}

char	**my_str_to_wordtab(char *str)
{
  char	**wordtab;
  int	nb_word;
  int	i;

  if (str == NULL)
    return (NULL);
  nb_word = find_nbr_word(str) + 1;
  if ((wordtab = malloc(nb_word * sizeof(*wordtab))) == NULL)
    return (NULL);
  if (recup_str_word(str, wordtab) < 0)
    return (NULL);
  return (wordtab);
}
