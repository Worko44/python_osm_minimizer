/*
** my_strcapitalize.c for my_strcapitalize in /home/lecuye_j/rendu/Piscine_C_J06/ex_09
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Mon Oct  6 16:28:45 2014 Johan Lecuyer
** Last update Mon Oct  6 17:59:54 2014 Johan Lecuyer
*/

#include <stdlib.h>

int	find_lettre_or_num(char c)
{
  if (c >= 'a' && c <= 'z')
    return (0);
  if (c >= 'A' && c <= 'Z')
    return (1);
  if (c >= '0' && c <= '9')
    return (2);
  return (-1);
}

char	*my_strcapitalize(char *str)
{
  int	i;
  int	nb;
  int	word;

  i = 0;
  if (str == NULL)
    return (str);
  nb = 0;
  while (str[i] != 0)
    {
      nb = find_lettre_or_num(str[i]);
      if (nb == 0 && word == 0)
	str[i] += 'A' - 'a';
      if (nb == 1 && word == 1)
	str[i] -= 'A' - 'a';
      if (nb >= 0)
	word = 1;
      else
	word = 0;
      i++;
    }
  return (str);
}
