/*
** my_strlen.c for my_strlen in /home/lecuye_j/rendu/Piscine_C_J04
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Thu Oct  2 10:40:42 2014 Johan Lecuyer
** Last update Tue Oct  7 11:30:59 2014 Johan Lecuyer
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}
