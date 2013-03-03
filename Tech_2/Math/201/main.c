/*
** main.c for 201yams in /home/belia-_r/afs/epitech_perso/Tech_2/Math/201
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Sat Mar  2 00:30:21 2013 romain belia-bourgeois
** Last update Sun Mar  3 18:12:56 2013 romain belia-bourgeois
*/
#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"201yams.h"

t_comb	comb[7] =
  {
    {"paire_", 6, paire},
    {"brelan_", 7, brelan},
    {"carre_", 6, carre},
    {"full_", 5, full},
    {"suite_", 6, suite},
    {"yams_", 5, yams},
    {NULL, 0, NULL}
  };

bool	check_des(int des)
{
  if (des >= 0 && des <= 6)
    return (true);
  return (false);
}

bool	recup_param(t_lancer *lancer, int i, char **av)
{
  int	tmp;

  i = 0;
  tmp = 0;
  while (i < 5)
    {
      tmp = atoi(av[i + 1]);
      if (check_des(tmp))
	lancer->des[i] = tmp;
      else
	return (false);
      i++;
    }
  lancer->comb = strdup(av[i + 1]);
  return (true);
}

bool	check_comb(t_lancer *lancer)
{
  int	i = 0;

  while ((comb[i].str) != NULL)
    {
      if (strncmp(comb[i].str, lancer->comb, comb[i].t) == 0)
	{
	  comb[i].fonc(lancer);
	  return (true);
	}
      i++;
    }
  return (false);
}

void	run(t_lancer *lancer)
{
  if (!(check_comb(lancer)))
    exit(EXIT_FAILURE);
  printf ("OKKKKKKKKKKKKK\n");
}

int	main(int ac, char **av)
{
  t_lancer	lancer;

  if ((ac != 7) || (!(recup_param(&lancer, ac, av))))
    {
      printf (USAGE);
      return (EXIT_FAILURE);
    }
  run(&lancer);
  free(lancer.comb);
  return (EXIT_SUCCESS);
}
