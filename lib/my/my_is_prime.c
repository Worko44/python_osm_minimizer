/*
** my_is_prime.c for my_is_prime in /home/lecuye_j/rendu/Piscine_C_J05
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Fri Oct  3 11:54:24 2014 Johan Lecuyer
** Last update Fri Oct  3 13:17:08 2014 Johan Lecuyer
*/

int	recurs_my_is_prime(int nb, int i)
{
  if (i >= nb)
    return (1);
  if (nb % i == 0)
    return (0);
  i++;
  return (recurs_my_is_prime(nb, i));
}

int	my_is_prime(int nb)
{
  if (nb <= 1)
    return (0);
  return (recurs_my_is_prime(nb, 2));
}
