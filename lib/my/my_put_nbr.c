/*
** my_put_nbr.c for my_put_nbr in /home/lecuye_j/rendu/test_Piscine/Piscine_C_J04
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Fri Oct  3 14:38:16 2014 Johan Lecuyer
** Last update Wed Oct 22 15:25:40 2014 Johan Lecuyer
*/

int	recurs_put_nbr(int nb, int neg, int i)
{
  int	mod;

  if (nb == 0)
    return (0);
  mod = nb % 10;
  recurs_put_nbr(nb / 10, neg, i + 1);
  if (mod < 0)
    mod *= -1;
  my_putchar(mod + '0');
  return (0);
}

int	my_put_nbr(int nb)
{
  int	neg;

  neg = 1;
  if (nb < 0)
    {
      my_putchar('-');
      neg = -1;
    }
  if (nb == 0)
    my_putchar('0');
  else
    recurs_put_nbr(nb, neg, 0);
  return (0);
}
