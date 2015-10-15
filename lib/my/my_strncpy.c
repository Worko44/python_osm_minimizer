/*
** my_strncpy.c for my_strncpy in /home/lecuye_j/rendu/Piscine_C_J06
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Mon Oct  6 09:53:11 2014 Johan Lecuyer
** Last update Mon Oct  6 14:04:25 2014 Johan Lecuyer
*/

#include <stdio.h>

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  if (dest == NULL || src == NULL || n <= 0)
    return (dest);
  while (i < n && src[i] != 0)
    {
      dest[i] = src[i];
      i++;
    }
  if (i < n)
    dest[i] = 0;
  return (dest);
}
