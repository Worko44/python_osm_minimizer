/*
** my_str_isalpha.c for my_str_isalpha.c in /home/lecuye_j/rendu/Piscine_C_J06/ex_10
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Mon Oct  6 16:39:35 2014 Johan Lecuyer
** Last update Mon Oct  6 16:50:08 2014 Johan Lecuyer
*/

#include <stdlib.h>

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != 0)
    {
      if (str[i] <= 'z' && str[i] >= 'a')
	i++;
      else if (str[i] <= 'Z' && str[i] >= 'A')
	i++;
      else
	return (0);
    }
  return (1);
}
