/*
** my_isneg.c for my_isneg in /home/lecuye_j/rendu/Piscine_C_J03
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Wed Oct  1 09:33:46 2014 Johan Lecuyer
** Last update Wed Oct  1 10:39:54 2014 Johan Lecuyer
*/

int	my_isneg(int n)
{
  if (n >= 0)
    my_putchar('P');
  else
    my_putchar('N');
  my_putchar('\n');
  return (0);
}
