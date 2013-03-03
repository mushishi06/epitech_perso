/*
** full.c for 201yams in /home/belia-_r/afs/epitech_perso/Tech_2/Math/201
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Thu Feb 28 19:03:23 2013 romain belia-bourgeois
** Last update Sun Mar  3 17:57:45 2013 romain belia-bourgeois
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"201yams.h"

int	get_two_param(char *str, int size, int *param_2)
{
  int	nb;

  nb = atoi(str + size);
  *param_2 = atoi(str + size + 2);
  if (*param_2 == 0 || nb == 0)
    return (-1);
  printf ("%c %c\n", (str[size + 1]), (str[size + 2]));
  printf ("nb1 = [%d] nb2 = [%d]\n", nb, *param_2);
  if (check_des(nb) && check_des(*param_2))
    return (nb);
  return (-1);
}

float	full(t_lancer *lancer)
{
  float	res = 0.0;
  int	nb1;
  int	nb2 = -1;

  nb1 = get_two_param(lancer->comb, 5, &nb2);
  if (nb1 == -1)
    exit(EXIT_FAILURE); // exit_error(lancer);
  printf ("probabilité d’obtenir un full de %i par les %i : %.02f %%\n", nb1, nb2, res);
  return (res);
}
