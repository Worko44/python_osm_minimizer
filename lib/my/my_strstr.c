/*
** my_strstr.c for my_strstr in /home/lecuye_j/rendu/Piscine_C_J06/ex_04
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Mon Oct  6 10:45:25 2014 Johan Lecuyer
** Last update Mon Oct 20 10:45:09 2014 Johan Lecuyer
*/

#include <stdio.h>

char	*my_strstr(char *str, char *to_find)
{
  int	i;

  i = 0;
  if (str == NULL || to_find == NULL)
    return (NULL);
  while (str[i] != 0)
    {
      if (my_strncmp(&str[i], to_find, my_strlen(to_find)) == 0)
	return (&str[i]);
      i++;
    }
  return (NULL);
}
