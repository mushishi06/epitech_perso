/*
** main.c for 202invendus in /home/belia-_r/afs/epitech_perso/Tech_2/Math/202
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Mon Mar  4 22:56:40 2013 romain belia-bourgeois
** Last update Wed Mar 13 18:56:38 2013 romain belia-bourgeois
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"202invendus.h"

void	init_var(double **tab, double **print, double **zab)
{
  int	i = 0;

  while (i < 7)
    {
      tab[i] = xmalloc(7 * sizeof(*tab));
      print[i] = xmalloc(7 * sizeof(*print));
      i++;
    }
  i = 0;
  while (i < 2)
    {
      zab[i] = xmalloc(11 * sizeof(*tab));
      i++;
    }
}

void	init_tab(double **tab, double **print, double **zab)
{
  tab[0][1] = 10;
  tab[0][2] = 20;
  tab[0][3] = 30;
  tab[0][4] = 40;
  tab[0][5] = 50;
  tab[1][0] = 10;
  tab[2][0] = 20;
  tab[3][0] = 30;
  tab[4][0] = 40;
  tab[5][0] = 50;
  zab[0][1] = 20;
  zab[0][2] = 30;
  zab[0][3] = 40;
  zab[0][4] = 50;
  zab[0][5] = 60;
  zab[0][6] = 70;
  zab[0][7] = 80;
  zab[0][8] = 90;
  zab[0][9] = 100;
  zab[0][10] = 0;
  print[0][1] = 10;
  print[0][2] = 20;
  print[0][3] = 30;
  print[0][4] = 40;
  print[0][5] = 50;
  print[1][0] = 10;
  print[2][0] = 20;
  print[3][0] = 30;
  print[4][0] = 40;
  print[5][0] = 50;
}

void	run(int a, int b)
{
  double	**tab;
  double	**zab;
  double	**print;

  tab = xmalloc(7 * sizeof(*tab));
  print = xmalloc(7 * sizeof(*print));
  zab = xmalloc(2 * sizeof(*zab));
  printf ("a = [%d] b = [%d]\n", a, b);
  init_var(tab, print, zab);
  init_tab(tab, print, zab);
  calc_loi_conj(tab, print, a, b);
  loi_marginale_X(tab, print);
  loi_marginale_Y(tab, print);
  total_marginale(tab, print);
  proba_z(tab, zab);
  print_results(print, zab);
}

int	main(int ac, char **av)
{
  int	a = 0;
  int	b = 0;

  if ((ac != 3) || (!(get_params(av, &a, &b))))
    {
      printf (USAGE);
      return (EXIT_FAILURE);
    }
  run(a, b);
  return (EXIT_SUCCESS);
}
