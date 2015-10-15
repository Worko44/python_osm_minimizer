/*
** my_strupcase.c for my_strupcase in /home/lecuye_j/rendu/Piscine_C_J06/ex_07
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Mon Oct  6 16:03:07 2014 Johan Lecuyer
** Last update Mon Oct  6 16:18:18 2014 Johan Lecuyer
*/

#include <stdlib.h>

char	*my_strupcase(char *str)
{
  int	i;

  if (str == NULL)
    return (str);
  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] += 'A' - 'a';
      i++;
    }
  return (str);
}
