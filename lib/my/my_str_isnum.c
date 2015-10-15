/*
** my_str_isnum.c for my_str_isnum in /home/lecuye_j/rendu/Piscine_C_J06/ex_11
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Mon Oct  6 18:15:34 2014 Johan Lecuyer
** Last update Mon Oct  6 18:19:53 2014 Johan Lecuyer
*/

#include <stdlib.h>

int	my_str_isnum(char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != 0)
    {
      if (str[i] <= '9' && str[i] >= '0')
	i++;
      else
	return (0);
    }
  return (1);
}
