/*
** my_find_prime_sup.c for my_find_prime_sup in /home/lecuye_j/rendu/Piscine_C_J05
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Fri Oct  3 13:25:59 2014 Johan Lecuyer
** Last update Fri Oct  3 13:29:59 2014 Johan Lecuyer
*/

int	recurs_find_prime_sup(int nb)
{
  if (recurs_my_is_prime(nb) == 1)
    return (nb);
  nb++;
  return (recurs_find_prime_sup(nb));
}

int	my_find_prime_sup(int nb)
{
  if (nb <= 1)
    return (2);
  return (recurs_find_prime_sup(nb));
}
