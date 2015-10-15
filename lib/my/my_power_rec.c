/*
** my_power_rec.c for my_power_rec in /home/lecuye_j/rendu/Piscine_C_J05
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Fri Oct  3 10:21:07 2014 Johan Lecuyer
** Last update Fri Oct  3 13:57:53 2014 Johan Lecuyer
*/

int	recurs_power(int i, int nb, int rsl, int power)
{
  if (i >= power)
    return (rsl);
  if (nb >= 0)
    {
      rsl *= nb;
      if (rsl < 0)
	return (0);
    }
  else
    {
      if (rsl < 0)
	{
	  rsl *= nb;
	  if (rsl < 0)
	    return (0);
	}
      else
	{
	  rsl *= nb;
	  if (rsl > 0)
	    return (0);
	}
    }
  i += 1;
  return (recurs_power(i, nb, rsl, power));
}

int	my_power_rec(int nb, int power)
{
  if (power < 0)
    return (0);
  return (recurs_power(0, nb, 1, power));
}
