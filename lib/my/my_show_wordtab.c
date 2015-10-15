/*
** my_show_wordtab.c for my_show_wordtab in /home/lecuye_j/rendu/Piscine_C_J08/ex_05
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Thu Oct  9 18:54:30 2014 Johan Lecuyer
** Last update Thu Oct  9 18:56:31 2014 Johan Lecuyer
*/

#include "my.h"

int	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i][0] != 0)
    {
      my_putstr(tab[i]);
      my_putstr("\n");
      i++;
    }
  return (0);
}
