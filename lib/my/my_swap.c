/*
** my_swap.c for my_swap in /home/lecuye_j/rendu/Piscine_C_J04
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Thu Oct  2 10:07:39 2014 Johan Lecuyer
** Last update Thu Oct  2 10:49:09 2014 Johan Lecuyer
*/

#include <stdio.h>

int	my_swap(int *a, int *b)
{
  int	c;

  if (a == NULL || b == NULL)
    return (0);
  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
