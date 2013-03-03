/*
** yams.c for 201yams in /home/belia-_r/afs/epitech_perso/Tech_2/Math/201
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Thu Feb 28 19:02:51 2013 romain belia-bourgeois
** Last update Sun Mar  3 19:44:29 2013 romain belia-bourgeois
*/

#include	<math.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"201yams.h"

float	yams_calc(t_lancer *lancer, int nc, int nb_oc)
{
  int	dl;

  dl = 6 - nb_oc;
  if(nb_oc == 5)
    {
      printf ("probabilité d’obtenir une paire de %d : 100%%\n", nc);
      return (100);
    }
  else
    return  ((dl / nc) * (pow((1 / 6 ), dl)) * (pow((5 / 6), nb_oc)));
}

float	yams(t_lancer *lancer)
{
  float	res = 0.0;
  int	nb;
  int	nb_oc = 0;

  nb = get_one_param(lancer->comb, 5);
  if (nb == -1)
    exit(EXIT_FAILURE); // exit_error(lancer);
  nb_oc = check_lancer(lancer->des, nb);
  res = yams_calc(lancer, nb, nb_oc);
  if (res != 100)
    printf ("probabilité d’obtenir un yams de %d : %.02f %%\n", nb, res);
  return (res);
}
