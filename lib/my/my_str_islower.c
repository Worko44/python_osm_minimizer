/*
** my_str_islower.c for my_str_islower in /home/lecuye_j/rendu/Piscine_C_J06/ex_11
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Mon Oct  6 18:29:09 2014 Johan Lecuyer
** Last update Mon Oct  6 18:29:46 2014 Johan Lecuyer
*/

#include <stdlib.h>

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != 0)
    {
      if (str[i] <= 'z' && str[i] >= 'a')
        i++;
      else
        return (0);
    }
  return (1);
}
