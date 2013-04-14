/*
** main.c for 204 in /home/belia-_r/afs/Math/204
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Apr 22 20:45:45 2012 belia-_r
** Last update Sun Apr 22 20:45:47 2012 belia-_r
*/

#include <stdlib.h>
#include <stdio.h>
#include "others.h"

t_rule34	tab[6] =
  {
    {inter1, "1/(5-2) si x appartient a [2,5]", 2.f, 5.f},
    {inter2, "1-|x| si x appartient a [-1,1]", -1.f, 1.f},
    {expo, "exp(-x) si x > 0", 0.f, 100.f},
    {gauss, "gauss0,1(x) = 1/sqrt(2pi) * exp(-x^2/2)", -10.f, 10.f},
    {gauss2, "gauss3,4(x) = 1/(2 * sqrt(2pi)) * exp(-(x - 3)^2 / 8)", -10.f, 20.f},
    {NULL, "", 0.f, 0.f}
  };

double		esp(double (*believe)(), double ko, double ok)
{
  double	inc;
  double	h;
  double	i;
  double	j;

  i = 0.f;
  j = 0.f;
  h = (double)((double)(ok - ko) / (double)ITER);
  for (inc = 1.f; inc <= (ITER - 1.f); inc += 1.f)
    {
      i += (ko + inc * h) * believe(ko + inc * h);
    }
  i *= 2.f;
  for (inc = 0.f; inc <= (ITER - 1.f); inc += 1.f)
    {
      j += (ko + inc * h + h / 2.f) * believe(ko + inc * h + h / 2.f);
    }
  j *= 4.f;
  return (((double)(ok - ko) / (6.f * ITER)) * (ko * believe(ko) + ok * believe(ok) + i + j));
}

double		var(double (*believe)(), double ko, double ok)
{
  double	inc;
  double	h;
  double	i;
  double	j;
  double	m;

  i = 0.f;
  j = 0.f;
  m = esp(believe, ko, ok);
  h = (double)((double)(ok - ko) / (double)ITER);
  for (inc = 1.f; inc <= (ITER - 1.f); inc += 1.f)
    {
      i += (((ko + inc * h) - m) * ((ko + inc * h) - m)) * believe(ko + inc * h);
    }
  i *= 2.f;
  for (inc = 0.f; inc <= (ITER - 1.f); inc += 1.f)
    {
      j += (((ko + inc * h + h / 2.f) - m) * ((ko + inc * h + h / 2.f) - m)) * believe(ko + inc * h + h / 2.f);
    }
  j *= 4.f;
  return (((double)(ok - ko) / (6.f * ITER)) * ((ko - m) * believe(ko) + (ok - m) * believe(ok) + i + j));
}

void		run()
{
  int		i;

  for (i = 0; tab[i].believe != NULL; i++)
    {
      printf("f(x) = %s\n", tab[i].info);
      printf("E(x) = %.3f\n", esp(tab[i].believe, tab[i].failboat, tab[i].wincopter));
      printf("Var(x) = %.3f\n\n", var(tab[i].believe, tab[i].failboat, tab[i].wincopter));
    }
}

int		main()
{
  run();
  return (EXIT_SUCCESS);
}
