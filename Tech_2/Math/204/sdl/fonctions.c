/*
** fonctions.c for SDL_math in /home/belia-_r/afs/epitech_perso/Tech_2/Math/204
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Tue Apr  9 14:12:08 2013 romain belia-bourgeois
** Last update Sun Apr 14 19:32:37 2013 romain belia-bourgeois
*/

#include	<SDL/SDL_gfxPrimitives.h>
#include	<math.h>
#include	"sdl_math.h"

double	fonc_rep(double a, double b, double p_a)
{
  double	tmp;

  tmp = ((b - a) / 6) * (f(p_a , b) + 4 * (f(p_a, ((a + b) / 2)) + f(p_a,b)));
  return (tmp);
}

double	fonc_test(double a, double b, double h, double n, double p_a, double total)
{
  int		t;
  double	tmp;
  double	t2 = 0;

  for (t = 0; t < 1000; t++)
    {
      t2 += f(p_a, a + t + (1 / 2));
    }
  tmp = ((b - a) / (6 * n)) * (f(p_a, a) + f(p_a, b) + (2 * total) + (4 * t2));
  printf ("%f\n",tmp);
  return (tmp);
}
double	f(double a, double t)
{
  double	e = 2.7182818284590452;
  double	tmp;

  tmp = (a * (pow(e, ( - t)))) + ((4 - 3 * a) * ( pow(e, (- 2 * t)))) + ((2 * a - 4) * ( pow(e, (- 4 * t))));
  return (tmp);
}

void	draw_func_densite(SDL_Surface *ecran, SDL_Surface *rectangle, double a)
{
  int		t;
  double	tmp;
  double	tmp2;
  SDL_Rect	position;
  Sint16	vx[1000];
  Sint16	vy[1000];
  Sint16	vz[1000];
  double	total = 0;

  for (t = 0; t < 1000; t++)
    {
      position.x = 50 + t;
      vx[t] = 50 + t;
      tmp = f(a, (t * 0.01));
      position.y = (WIN_HEIGHT - 166) - tmp * 600;
      vy[t] = (WIN_HEIGHT - 166) - tmp * 600;
      total += vy[t];
      pixelColor(ecran, vx[t], vy[t], 0xff3a2aff);
      if (t > 0)
       	lineColor(ecran, vx[t - 1], vy[t - 1], vx[t], vy[t], 0xff3a2aff);
      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 100, 25));
      // polygonColor(ecran, vx, vy, 1000, 0xffa02aff);
      // SDL_BlitSurface(rectangle, NULL, ecran, &position);
    }
  for (t = 0; t < 1000; t++)
    {
      vx[t] = 50 + t;
      //      tmp2 = fonc_test(0, 1000, 1, 1000, a, total);
      tmp2 = fonc_rep(0, t, a);
      vz[t] =  (WIN_HEIGHT - 166) - tmp2 * 600;
      pixelColor(ecran, vx[t], vz[t], 0x3a3affff);
      if (t > 0)
	lineColor(ecran, vx[t - 1], vz[t - 1], vx[t], vz[t], 0x3a3affff);
    }
  SDL_Flip(ecran);
}

void	draw_legend(SDL_Surface *ecran)//, SDL_Surface *rectangle, int x, int y)
{
  rectangleColor(ecran, 1150, 400, 950, 500, 0xffffffff);
  stringColor(ecran, 1000, 430, "densite", 0xff3a2aff);
  stringColor(ecran, 1000, 460, "repartition", 0x3a3affff);
  SDL_Flip(ecran);
}
