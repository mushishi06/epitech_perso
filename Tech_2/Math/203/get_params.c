/*
** get_params.c for 203hotline in /home/belia-_r/afs/epitech_perso/Tech_2/Math/203
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Wed Mar 20 21:49:28 2013 romain belia-bourgeois
** Last update Thu Mar 21 23:38:56 2013 romain belia-bourgeois
*/

#include	<stdlib.h>
#include	"203hotline.h"

bool		get_params(char **av, int *a, int *b, int para)
{
  if (para == 1)
    {
      if (check_params(av[1]))
	{
	  *a = atoi(av[1]);
	  if (*a > 0)
	    return (true);
	}
      return (false);
    }
  else
    if (check_params(av[1]) && check_params(av[2]))
      {
	*a = atoi(av[1]);
	*b = atoi(av[2]);
	if (*a > 0 && *b > 0)
	  return (true);
      }
  return (false);
}
