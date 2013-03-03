/*
** suite.c for 201yams in /home/belia-_r/afs/epitech_perso/Tech_2/Math/201
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Thu Feb 28 19:03:15 2013 romain belia-bourgeois
** Last update Sun Mar  3 16:48:07 2013 romain belia-bourgeois
*/

#include	<stdio.h>
#include	"201yams.h"

float	suite(t_lancer *lancer)
{
  float	res = 0.0;
  int	nb = 0;

  if (nb == 5)
    printf ("probabilité d’obtenir une petite suite : %2.f %%\n", res);
  else
    printf ("probabilité d’obtenir une grande suite : %2.f %%\n", res);
  return (res);
}
