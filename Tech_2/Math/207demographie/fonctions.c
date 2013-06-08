/*
** fonctions.c for 207demographie in /home/belia-_r/afs/epitech_perso/Tech_2/Math/207demographie
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Jun  2 16:41:13 2013 romain belia-bourgeois
** Last update Sun Jun  2 22:28:18 2013 romain belia-bourgeois
*/

#include	<math.h>
#include	"sdl_math.h"


void	calcul_coef_ajust(double x[], double y[], int n, double *a, double *b, double *ecty)
{
  int		i, rt = 0;
  double	xsomme, ysomme, xysomme, xxsomme;
  double	ai,bi;
  double	ymoinsymoyene = 0.0, ymoyene;

  xsomme = 0.0;
  ysomme = 0.0;
  xysomme = 0.0;
  xxsomme = 0.0;
  for (i=0;i<n;i++)
    {
      if (y[i] > 0)
	{
	  xsomme = xsomme + x[i];
	  ysomme = ysomme + y[i];
	  xysomme = xysomme + x[i]*y[i];
	  xxsomme = xxsomme + x[i]*x[i];
	  rt++;
	}
    }
  ymoyene = ysomme / rt;
  for (i=0;i<n;i++)
    {
      ymoinsymoyene += (y[i] - ymoyene);
    }
  *ecty = sqrt(ymoinsymoyene * ymoinsymoyene / n);
  ai = (rt * xysomme - xsomme * ysomme) / (rt * xxsomme - xsomme * xsomme);
  *b = (ysomme * xxsomme - xsomme * xysomme) / (rt * xxsomme - xsomme * xsomme);
  bi = (ysomme - ai * xsomme) / rt;
  *a = (rt * xysomme - xsomme * ysomme) / (rt * xxsomme - xsomme * xsomme);
  //  *a = ai;
  // *b = bi;
  return;
}

double		calcul_y(double a, double b, double x)
{
  double	y = 0;

  y = a * x + b;
  return (y);
}
