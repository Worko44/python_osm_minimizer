/*
** get_next_line.c for get_next_line in /home/lecuye_j/rendu/CPE_2014_get_next_line/src
** 
** Made by Johan Lecuyer
** Login   <lecuye_j@epitech.net>
** 
** Started on  Wed Nov 19 10:29:11 2014 Johan Lecuyer
** Last update Fri Nov 21 15:45:33 2014 Johan Lecuyer
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int		find_ligne_strlen(char *buffer, int curs,
				  int flag)
{
  while (buffer[curs] != 0)
    {
      if (flag == 0 && (buffer[curs] == '\n' || buffer[curs] == EOF))
	return (curs);
      curs += 1;
    }
  if (flag == 1)
    return (curs);
  return (-1);
}

char    *my_strcatgnl(char *dest, char *src)
{
  int   size;
  int   i;

  if (dest == NULL || src == NULL)
    return (dest);
  size = find_ligne_strlen(dest, 0, 1);
  i = 0;
  while (src[i] != 0)
    {
      dest[size + i] = src[i];
      i++;
    }
  dest[size + i] = 0;
  return (dest);
}

char		*recup_buffer(char *str, char buffer[SIZE_BUFF + 1], int curs)
{
  char		*str2;
  int		size;
  int		size_str;

  size_str = 0;
  if (str != NULL)
    size_str = find_ligne_strlen(str, 0, 1);
  size = size_str + find_ligne_strlen(buffer, curs, 1) + 4;
  if ((str2 = malloc(size * sizeof(*str2))) == NULL)
    return (NULL);
  str2[0] = 0;
  if (str != NULL)
    str2 = my_strcatgnl(str2, str);
  str2 = my_strcatgnl(str2, &buffer[curs]);
  if (str != NULL)
    free(str);
  return (str2);
}

char		*put_buffer_in_str(char *str, char buffer[SIZE_BUFF + 1],
				   int *curs, int *i)
{
  int		n;
  int		end;

  end = 0;
  if (buffer[*curs] == EOF)
    {
      *i = -2;
      *curs = 0;
      return (str);
    }
  n = *curs;
  if ((*i = find_ligne_strlen(buffer, *curs, 0)) != -1)
    {
      if (buffer[*i] == EOF)
	end = 1;
      buffer[*i] = 0;
      n = *i + 1;
      if (n >= SIZE_BUFF || end == 1)
	n = 0;
    }
  str = recup_buffer(str, buffer, *curs);
  *curs = n;
  return (str);
}

char		*get_next_line(const int fd)
{
  static char	buffer[SIZE_BUFF + 1];
  static int	curs = 0;
  char		*str;
  int		n;
  int		i;

  str = NULL;
  if (curs != 0)
    {
      str = put_buffer_in_str(str, buffer, &curs, &i);
      if (i != -1)
	return (str);
    }
  while ((n = read(fd, buffer, SIZE_BUFF)) > 0)
    {
      buffer[n] = 0;
      curs = 0;
      str = put_buffer_in_str(str, buffer, &curs, &i);
      if (i >= 0)
	return (str);
    }
  curs = 0;
  return (str);
}
