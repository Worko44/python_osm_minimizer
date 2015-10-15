/*
** my_strcmp.c for my_strcmp in /home/lecuye_j/rendu/Piscine_C_J06/ex_05
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Mon Oct  6 10:51:25 2014 Johan Lecuyer
** Last update Wed Oct 22 15:08:06 2014 Johan Lecuyer
*/

#include <stdio.h>

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  if (s1 == NULL || s2 == NULL)
    return (-1);
  i = 0;
  while (42)
    {
      if (s1[i] < s2[i])
	return (-1);
      else if (s1[i] > s2[i])
	return (1);
      else if (s1[i] == 0)
	return (0);
      i++;
    }
  return (0);
}
