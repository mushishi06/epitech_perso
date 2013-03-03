/*
** carre.c for 201yams in /home/belia-_r/afs/epitech_perso/Tech_2/Math/201
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Thu Feb 28 19:03:31 2013 romain belia-bourgeois
** Last update Sun Mar  3 23:47:00 2013 romain belia-bourgeois
*/

#include	<math.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"201yams.h"

float	carre_calc(t_lancer *lancer, int nc, int nb_oc)
{
  int	dl = 0;
  float	res = 0;

  dl = 6 - nb_oc;
  if(nb_oc >= 4)
    {
      printf ("probabilité d’obtenir un carré de %d : 100%%\n", nc);
      return (100);
      /*      if (nb_oc > 4)
	      return (yams_calc(lancer, nc, nb_oc));*/
    }
  else
    {
      res = (pow((1 / 6), 3));
      printf ("{%0.02f}\n", res);
      return  (res);
    }
}

float	carre(t_lancer *lancer)
{
  float	res = 0.0;
  int	nb;
  int	nb_oc = 0;

  nb = get_one_param(lancer->comb, 6);
  if (nb == -1)
    exit(EXIT_FAILURE); // exit_error(lancer);
  nb_oc = check_lancer(lancer->des, nb);
  res = carre_calc(lancer, nb, nb_oc);
  if (res != 100)
    printf ("probabilité d’obtenir un carré de %i : %.02f %%\n", nb, res);
  return (res);
}
