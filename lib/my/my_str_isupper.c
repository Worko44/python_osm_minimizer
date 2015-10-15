/*
** my_str_isupper.c for my_str_isupper in /home/lecuye_j/rendu/Piscine_C_J06/ex_13
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Mon Oct  6 18:32:01 2014 Johan Lecuyer
** Last update Mon Oct  6 18:32:34 2014 Johan Lecuyer
*/

#include <stdlib.h>

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != 0)
    {
      if (str[i] <= 'Z' && str[i] >= 'A')
        i++;
      else
        return (0);
    }
  return (1);
}
