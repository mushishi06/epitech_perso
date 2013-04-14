/*
** loi.c for 203hotline in /home/belia-_r/afs/epitech_perso/Tech_2/Math/203
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Wed Mar 20 21:48:43 2013 romain belia-bourgeois
** Last update Wed Mar 20 21:48:52 2013 romain belia-bourgeois
*/

#include	<stdio.h>
#include	<math.h>
#include	"203hotline.h"

double	loi_conjointe(int a, int b, int x, int y)
{
  double	res_1;
  double	res_2;
  double	res;


  res_1 = ((a - x) * (b - y));
  res_2 = (((5 * a) - 150) * ((5 * b) - 150));
  res = res_1 / res_2;
  return (res);
}

void	calc_loi_conj(double **tab, double **print, int a, int b)
{
  int	i = 1;
  int	j = 1;
  double	tmp;

  while (j < 6)
    {
      i = 1;
      while (i < 6)
	{
	  tmp = loi_conjointe(a, b, (int)tab[0][i], (int)tab[j][0]);
	  tab[j][i] = tmp;
	  print[j][i] = darrondi(tmp);
	  i++;
	}
      j++;
    }
}

void	loi_marginale_X(double **tab, double **print)
{
  int	i = 1;
  int	j = 1;

  while (i < 6)
    {
      j = 1;
      while (j < 6)
	{
	  tab[6][i] += tab[j][i];
	  print[6][i] += tab[j][i];
	  j++;
	}
      i++;
    }
}

void	loi_marginale_Y(double **tab, double **print)
{
  int	i = 1;
  int	j = 1;

  while (j < 6)
    {
      i = 1;
      while (i < 6)
	{
	  tab[j][6] += tab[j][i];
	  print[j][6] += tab[j][i];
	  i++;
	}
      j++;
    }
}

void	total_marginale(double **tab, double **print)
{
  int	i = 1;
  int	j = 1;
  double	res = 0;

  while (i < 6)
    {
      tab[6][6] += tab[6][i];
      i++;
    }
  while (j < 6)
    {
      res += tab[j][6];
      j++;
    }
  if (tab[6][6] > res)
    tab[6][6] = res;
  print[6][6] = res;
}

void	proba_z(double **tab, double **zab)
{
  int	i = 1;
  int	j = 1;
  int	k = 1;

  while (j < 6)
    {
      i = 1;
      while (i < 6)
	{
	  k = 1;
	  while (k < 10)
	    {
	      if (zab[0][k] == (tab[0][i] + tab[j][0]))
		zab[1][k] += darrondi(tab[j][i]);
	      k++;
	    }
	  i++;
	}
      j++;
    }
  k = 1;
  while (k < 10)
    {
      zab[1][10] += zab[1][k];
      k++;
    }
}

double		esperance(double x, double loi_x)
{
  return (x * loi_x);
}

double		variance(double x, double loi_x)
{
  double	res;

  res = (pow(x, 2) * loi_x);
  return (res);
}

double		esp_x(double **tab)
{
  int		i = 1;
  double	res = 0;

  while (i < 6)
    {
      res += esperance(tab[0][i], tab[6][i]);
      i++;
    }
  return (res);
}

double		var_x(double **tab)
{
  int		i = 1;
  double	res = 0;

  while (i < 6)
    {
      res += variance(tab[0][i], tab[6][i]);
      i++;
    }
  res = res - (pow(esp_x(tab), 2));
  return (res);
}

double		esp_y(double **tab)
{
  int		i = 1;
  double	res = 0;

  while (i < 6)
    {
      res += esperance(tab[i][0], tab[i][6]);
      i++;
    }
  return (res);
}

double		var_y(double **tab)
{
  int		i = 1;
  double	res = 0;

  while (i < 6)
    {
      res += variance(tab[i][0], tab[i][6]);
      i++;
    }
  res = res - (pow(esp_y(tab), 2));
  return (res);
}

double		esp_z(double **tab)
{
  int		i = 1;
  double	res = 0;

  while (i < 11)
    {
      res += esperance(tab[0][i], tab[1][i]);
      i++;
    }
  return (res);
}

double		var_z(double **tab)
{
  int		i = 1;
  double	res = 0;

  while (i < 11)
    {
      res += variance(tab[0][i], tab[1][i]);
      i++;
    }
  res -=  (pow(esp_z(tab), 2));
  return (res);
}
