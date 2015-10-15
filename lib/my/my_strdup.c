/*
** my_strdup.c for my_strdup in /home/lecuye_j/rendu/Piscine_C_J08/ex_01
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Wed Oct  8 09:24:54 2014 Johan Lecuyer
** Last update Wed Oct  8 11:44:38 2014 Johan Lecuyer
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  int	size;
  char	*dest;

  if (src == NULL)
    return (NULL);
  size = my_strlen(src) + 1;
  if ((dest = malloc(size * sizeof(*dest))) == NULL)
    return (NULL);
  return (my_strcpy(dest, src));
}
