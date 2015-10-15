/*
** my_strncat.c for my_strncat in /home/lecuye_j/rendu/Piscine_C_J07/ex_01
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Tue Oct  7 15:39:07 2014 Johan Lecuyer
** Last update Tue Oct  7 15:45:25 2014 Johan Lecuyer
*/

#include <stdio.h>

char	*my_strncat(char *dest, char *src, int nb)
{
  int	size;
  int	i;

  if (dest == NULL || src == NULL || nb <= 0)
    return (dest);
  size = my_strlen(dest);
  i = 0;
  while (src[i] != 0 && i < nb)
    {
      dest[size + i] = src[i];
      i++;
    }
  dest[size + i] = 0;
  return (dest);
}
