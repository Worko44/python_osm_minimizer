/*
** my_putstr.c for my_putstr in /home/lecuye_j/rendu/Piscine_C_J04
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Thu Oct  2 10:34:17 2014 Johan Lecuyer
** Last update Thu Oct  2 10:39:23 2014 Johan Lecuyer
*/

#include <stdlib.h>

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (-1);
  while (str[i] != 0)
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}
