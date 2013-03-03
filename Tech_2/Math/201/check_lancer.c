/*
** check_lancer.c for 201yams in /home/belia-_r/afs/epitech_perso/Tech_2/Math/201
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Mar  3 18:13:49 2013 romain belia-bourgeois
** Last update Sun Mar  3 18:28:51 2013 romain belia-bourgeois
*/

#include	<stdio.h>
#include	"201yams.h"

int	check_lancer(int *lancer, int nc)
{
  int	nb_oc = 0;
  int	i = 0;

  while (i < 5)
    {
      if (lancer[i]  == nc)
	nb_oc++;
      i++;
    }
  return (nb_oc);
}
