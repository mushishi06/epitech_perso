/*
** darrondi.c for 202invendus in /home/belia-_r/afs/epitech_perso/Tech_2/Math/202
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Wed Mar 13 16:39:12 2013 romain belia-bourgeois
** Last update Wed Mar 13 18:43:31 2013 romain belia-bourgeois
*/

#include <math.h>

double	darrondi(double val)
{
  double	fvaleur;
  double	fdecimal;
  int		ires;

  fvaleur = (val * 1000);
  if (fvaleur < 0)
    {
      fdecimal = fvaleur - ceil(fvaleur);
      if (fdecimal > -0.5)
	ires = ceil(fvaleur);
      else
	ires = floor(fvaleur);
    }
  else
    {
      fdecimal = fvaleur - floor(fvaleur);
      if (fdecimal < 0.5)
	ires = floor(fvaleur);
      else
	ires = ceil(fvaleur);
    }
  fvaleur = ((double)ires / 1000);
  return (fvaleur);
}
