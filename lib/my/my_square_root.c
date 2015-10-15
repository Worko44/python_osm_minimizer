/*
** my_square_root.c for my_square_root in /home/lecuye_j/rendu/Piscine_C_J05
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Fri Oct  3 11:44:17 2014 Johan Lecuyer
** Last update Fri Oct  3 11:47:49 2014 Johan Lecuyer
*/

int	my_recurs_square_root(int nb, int i)
{
  if (i * i == nb)
    return (i);
  else if (i * i > nb)
    return (0);
  i++;
  return (my_recurs_square_root(nb, i));
}

int	my_square_root(int nb)
{
  if (nb <= 0)
    return (0);
  return (my_recurs_square_root(nb, 1));
}
