/*
** my_str_isprintable.c for my_str_isprintable in /home/lecuye_j/rendu/Piscine_C_J06/ex_14
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Mon Oct  6 19:14:59 2014 Johan Lecuyer
** Last update Mon Oct  6 19:55:56 2014 Johan Lecuyer
*/

#include <stdlib.h>

int	my_str_isprintable(char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= 32 && str[i] <= 176)
	i++;
      else
	return (0);
    }
  return (1);
}
