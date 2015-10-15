/*
** my_puterror.c for my_puterror in /home/lecuye_j/rendu/PSU_2014_my_ls/src
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Wed Oct 29 15:35:20 2014 Johan Lecuyer
** Last update Wed Oct 29 15:43:25 2014 Johan Lecuyer
*/

#include <stdio.h>
#include "my.h"

void	*my_puterrorp(char *err)
{
  write(2, err, my_strlen(err));
  return (NULL);
}

int	my_puterrori(char *err)
{
  write(2, err, my_strlen(err));
  return (-1);
}
