/*
** paire.c for 201yams in /home/belia-_r/afs/epitech_perso/Tech_2/Math/201
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Thu Feb 28 19:04:02 2013 romain belia-bourgeois
** Last update Sun Mar  3 19:46:34 2013 romain belia-bourgeois
*/

#include	<math.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"201yams.h"

int	get_one_param(char *str, int size)
{
  int	nb;

  nb = atoi(str + size);
  if (check_des(nb) && (nb != 0))
    return (nb);
  return (-1);
}

float	paire_calc(t_lancer *lancer, int nc, int nb_oc)
{
  int	dl;

  dl = 6 - nb_oc;
  if(nb_oc >= 2)
    {
      printf ("probabilité d’obtenir une paire de %d : 100%%\n", nc);
      return (100);
      /*      if (nb_oc > 2)
	      return (brelan_calc(lancer, nc, nb_oc));*/
    }
  else
    return  ((dl / nc) * (pow((1 / 6 ), dl)) * (pow((5 / 6), nb_oc)));
}

float	paire(t_lancer *lancer)
{
  float	res = 0.0;
  int	nb;
  int	nb_oc = 0;

  nb = get_one_param(lancer->comb, 6);
  if (nb == -1)
    exit(EXIT_FAILURE); // exit_error(lancer);
  nb_oc = check_lancer(lancer->des, nb);
  res = paire_calc(lancer, nb, nb_oc);
  if (res != 100)
    printf ("probabilité d’obtenir une paire de %d : %.02f %%\n", nb, res);
  return (res);
}
