/*
** my_revstr.c for my_revstr in /home/lecuye_j/rendu/Piscine_C_J06
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Mon Oct  6 10:24:25 2014 Johan Lecuyer
** Last update Mon Oct 20 10:10:14 2014 Johan Lecuyer
*/

#include <stdio.h>

char	*my_revstr(char *str)
{
  int	i;
  int	size;
  char	c;

  i = 0;
  if (str == NULL)
    return (str);
  size = my_strlen(str) - 1;
  while (i < size)
    {
      c = str[i];
      str[i] = str[size];
      str[size] = c;
      i++;
      size--;
    }
  return (str);
}
