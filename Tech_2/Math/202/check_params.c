/*
** check_params.c for 202invendus in /home/belia-_r/afs/epitech_perso/Tech_2/Math/202
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Mon Mar  4 23:12:05 2013 romain belia-bourgeois
** Last update Sun Mar 10 15:12:33 2013 romain belia-bourgeois
*/

#include	"202invendus.h"

bool		check_params(char *str)
{
  int	i = 0;

  while (str[i] != '\0')
    {
      if (str[i] < '0' && str[i] > '9')
	return (false);
      i++;
    }
  return (true);
}
