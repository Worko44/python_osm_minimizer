/*
** my_strlcat.c for my_strlcat in /home/lecuye_j/rendu/Piscine_C_J07/ex_05
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Wed Oct  8 09:13:49 2014 Johan Lecuyer
** Last update Wed Oct  8 10:36:37 2014 Johan Lecuyer
*/

#include <stdio.h>

int	my_strlcat(char *dest, char *src, int size)
{
  int	size_dest;
  int	size_src;
  int	i;

  if (dest == NULL || src == NULL)
    return (0);
  size_dest = my_strlen(dest);
  size_src = my_strlen(src);
  if (size_dest > size)
    return (size + 1);
  i = 0;
  while (i + size_dest < size - 1 && src[i] != 0)
    {
      dest[size_dest + i] = src[i];
      i++;
    }
  dest[size_dest + i] = 0;
  if (src[i] != 0)
    return (size_src + size_dest);
  return (size_dest + i);
}
