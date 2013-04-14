/*
** check_params.c for 203hotline in /home/belia-_r/afs/epitech_perso/Tech_2/Math/203
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Wed Mar 20 21:50:13 2013 romain belia-bourgeois
** Last update Wed Mar 20 21:50:19 2013 romain belia-bourgeois
*/

#include	"203hotline.h"

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
