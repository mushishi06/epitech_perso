/*
** get_params.c for 202invendus in /home/belia-_r/afs/epitech_perso/Tech_2/Math/202
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Mon Mar  4 23:11:06 2013 romain belia-bourgeois
** Last update Sun Mar 10 15:25:08 2013 romain belia-bourgeois
*/

#include	<stdlib.h>
#include	"202invendus.h"

bool		get_params(char **av, int *a, int *b)
{
  if (check_params(av[1]) && check_params(av[2]))
    {
      *a = atoi(av[1]);
      *b = atoi(av[2]);
      if (*a > 50 && *b > 50)
	return (true);
    }
  return (false);
}
