/*
** brelan.c for 201yams in /home/belia-_r/afs/epitech_perso/Tech_2/Math/201
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Thu Feb 28 19:03:49 2013 romain belia-bourgeois
** Last update Sun Mar  3 19:19:02 2013 romain belia-bourgeois
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"201yams.h"

float	brelan_calc(t_lancer *lancer, int nc, int nb_oc)
{
  if(nb_oc >= 3)
    {
      printf ("probabilité d’obtenir un brelan de %i : 100%%\n", nc);
      return (100);
      /*      if (nb_oc > 3)
	      return (carre_calc(lancer, nc, nb_oc));*/
    }
  else
    {

      return (10);
    }
}

float	brelan(t_lancer *lancer)
{
  float	res = 0.0;
  int	nb;
  int	nb_oc = 0;

  nb = get_one_param(lancer->comb, 7);
  if (nb == -1)
    exit(EXIT_FAILURE); // exit_error(lancer);
  nb_oc = check_lancer(lancer->des, nb);
  res = brelan_calc(lancer, nb, nb_oc);
  if (res != 100)
    printf ("probabilité d’obtenir un brelan de %i : %2.f %%\n", nb, res);
  return (res);
}
