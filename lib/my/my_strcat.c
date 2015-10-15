/*
** my_strcat.c for my_strcat in /home/lecuye_j/rendu/Piscine_C_J07/ex_01
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Tue Oct  7 11:01:57 2014 Johan Lecuyer
** Last update Tue Oct  7 14:34:19 2014 Johan Lecuyer
*/

#include <stdio.h>

char	*my_strcat(char *dest, char *src)
{
  int	size;
  int	i;

  if (dest == NULL || src == NULL)
    return (dest);
  size = my_strlen(dest);
  i = 0;
  while (src[i] != 0)
    {
      dest[size + i] = src[i];
      i++;
    }
  dest[size + i] = 0;
  return (dest);
}
