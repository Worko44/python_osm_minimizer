/*
** my_strcpy.c for my_strcpy in /home/lecuye_j/rendu/Piscine_C_J06
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Mon Oct  6 09:35:53 2014 Johan Lecuyer
** Last update Mon Oct  6 10:01:54 2014 Johan Lecuyer
*/

#include <stdio.h>

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  if (dest == NULL || src == NULL)
    return (dest);
  i = 0;
  while (src[i] != 0)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}
