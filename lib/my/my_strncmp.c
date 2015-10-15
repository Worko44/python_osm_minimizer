/*
** my_strncmp.c for my_strncmp in /home/lecuye_j/rendu/Piscine_C_J06/ex_06
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Mon Oct  6 11:31:58 2014 Johan Lecuyer
** Last update Mon Oct 20 10:10:58 2014 Johan Lecuyer
*/

#include <stdio.h>

int	return_test(char *s1, char *s2, int n, int i)
{
  if (i == n)
    return (0);
  if (s1[i] < s2[i])
    return (-1);
  else if (s1[i] > s2[i])
    return (1);
  return (0);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	size_s1;
  int	size_s2;
  int	i;

  if (s1 == NULL || s2 == NULL)
    return (1);
  if (n < 0)
    n = 2147483647;
  size_s1 = my_strlen(s1);
  size_s2 = my_strlen(s2);
  i = 0;
  while (s1[i] != 0 && s2[i] != 0 && i < n)
    {
      if (s1[i] < s2[i])
	return (-1);
      else if (s1[i] > s2[i])
	return (1);
      i++;
    }
  return (return_test(s1, s2, n, i));
}
