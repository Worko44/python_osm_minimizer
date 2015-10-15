/*
** my_strlowcase.c for my_strlowcase in /home/lecuye_j/rendu/Piscine_C_J06/ex_08
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Mon Oct  6 16:22:14 2014 Johan Lecuyer
** Last update Mon Oct  6 16:25:18 2014 Johan Lecuyer
*/

#include <stdlib.h>

char	*my_strlowcase(char *str)
{
  int	i;

  if (str == NULL)
    return (str);
  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
        str[i] -= 'A' - 'a';
      i++;
    }
  return (str);
}
