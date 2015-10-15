/*
** my_getnbr.c for my_getnbr in /home/lecuye_j/rendu/Piscine_C_J04
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Thu Oct  2 11:08:23 2014 Johan Lecuyer
** Last update Fri Oct  3 14:25:22 2014 Johan Lecuyer
*/

#include <stdlib.h>

int	find_base(char *str, char *base)
{
  int	i;
  int	n;

  i = 0;
  while (str[i] != 0)
    {
      n = 0;
      while (base[n] != 0)
	{
	  if (str[i] == base[n])
	    return (i);
	  n++;
	}
      i++;
    }
  return (-1);
}

int	it_is_a_chiffre(char c, char *base)
{
  int	i;

  i = 0;
  while (base[i] != 0)
    {
      if (c == base[i])
	return (0);
      i++;
    }
  return (-1);
}

int	test_limite_nbr(char c, int nbr, int neg)
{
  if (neg == 1)
    {
      if (nbr >= 1000000000 || (nbr >= 214748364 && c > '7'))
	return (-1);
    }
  else
    {
      if (nbr <= -1000000000 || (nbr <= -214748364 && c > '8'))
	return (-1);
    }
  return (0);
}

int	translate_char_nb(char *str, char *base, int neg)
{
  int	i;
  int	nbr;

  nbr = 0;
  i = 0;
  while (str[i] != 0)
    {
      if (it_is_a_chiffre(str[i], base) == -1)
	return (nbr);
      else if (test_limite_nbr(str[i], nbr, neg) == -1)
	return (0);
      else
	nbr = nbr * 10 + (str[i] - '0') * neg;
      i++;
    }
  return (nbr);
}

int	my_getnbr(char *str)
{
  char	*base;
  int	neg;
  int	i;
  int	n;

  base = "0123456789";
  if (str == NULL)
    return (0);
  if ((i = find_base(str, base)) == -1)
    return (0);
  neg = 1;
  n = i;
  while (n > 0)
    {
      if (str[n - 1] == '-')
	neg *= -1;
      else if (str[n - 1] != '+')
	break;
      n--;
    }
  return (translate_char_nb(&str[i], base, neg));
}
