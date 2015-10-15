/*
** my_sort_int_tab.c for my_sort_int_tab in /home/lecuye_j/rendu/Piscine_C_J04
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Thu Oct  2 12:02:29 2014 Johan Lecuyer
** Last update Thu Oct  2 13:28:48 2014 Johan Lecuyer
*/

#include <stdio.h>

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	val;

  if (tab != NULL && size > 0)
    {
      i = 0;
      val = 0;
      while (i < size)
	{
	  if (i == 0)
	    val = tab[i];
	  else
	    {
	      if (val > tab[i])
		{
		  tab[i - 1] = tab[i];
		  tab[i] = val;
		  i = -1;
		}
	      else
		val = tab[i];
	    }
	  i++;
	}
    }
}
