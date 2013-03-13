/*
** print_results.c for 202invendus in /home/belia-_r/afs/epitech_perso/Tech_2/Math/202
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Mar 10 15:47:35 2013 romain belia-bourgeois
** Last update Wed Mar 13 19:15:08 2013 romain belia-bourgeois
*/

#include	<stdio.h>
#include	"202invendus.h"

void	print_results(double **tab, double **zab)
{
  int	i = 1;

  printf (" \tX=10\tX=20\tX=30\tX=40\tX=50\tloi de Y\n");
  while (i < 6)
    {
      printf ("Y=%d\t%.3g\t%.3g\t%.3g\t%.3g\t%.3g\t%.3g\n", (int)tab[i][0],
	      tab[i][1], tab[i][2], tab[i][3], tab[i][4], tab[i][5],tab[i][6]);
      i++;
    }
  printf ("loi X\t%.3g\t%.3g\t%.3g\t%.3g\t%.3g\t%.3g\n",
	  tab[i][1], tab[i][2], tab[i][3], tab[i][4], tab[i][5],tab[i][6]);

  printf ("z\t%.3g\t%.3g\t%.3g\t%.3g\t%.3g\t%.3g\t%.3g\t%.3g\t%.3g\ttotal\n",
	  zab[0][1], zab[0][2], zab[0][3], zab[0][4], zab[0][5],zab[0][6],
	  zab[0][7], zab[0][8], zab[0][9]);
  printf ("p(Z=z)\t%.3g\t%.3g\t%.3g\t%.3g\t%.3g\t%.3g\t%.3g\t%.3g\t%.3g\t%.3g\n",
	  zab[1][1], zab[1][2], zab[1][3], zab[1][4], zab[1][5],zab[1][6],
	  zab[1][7], zab[1][8], zab[1][9], zab[1][10]);
  printf ("esperance de X:\t%.03f\n", esp_x(tab));
  printf ("variance de X:\t%.03f\n", var_x(tab));
  printf ("esperance de Y:\t%g\n", esp_y(tab));
  printf ("variance de Y:\t%g\n", var_y(tab));
  printf ("esperance de Z:\t%g\n", esp_z(zab));
  printf ("variance de Z:\t%g\n", var_z(zab));
}
