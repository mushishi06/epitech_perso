/*
** fonctions.c for 205Qi in /home/belia-_r/afs/epitech_perso/Tech_2/Math/205
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Sun May  5 12:51:16 2013 romain belia-bourgeois
** Last update Sun May  5 14:05:19 2013 romain belia-bourgeois
*/

#include	<SDL/SDL_gfxPrimitives.h>
#include	<math.h>
#include	"sdl_math.h"

void	draw_func_rep(SDL_Surface *ecran, SDL_Surface *rectangle, double ect, double u)
{
  int		t, i = 0;
  double	t2;
  double	tmp;
  Sint16	vx[200];
  Sint16	vy[200];
  double	total = 0;

  for ((t = 0, t2 = 0); t2 < 200; (t2 += 0.01))
    {
      tmp = gauss(ect, u, (t2));
      if( i == 100)
	{
	  t++;
	  vx[t] = (int)(50 + t * OFFSET_W);
	  vy[t] = (WIN_HEIGHT - 50) - (total + tmp) * OFFSET_H;
	  i = 0;
	  //	  printf ("gauss [%f] = [%f]\n", (t2), total);
	}
      total += tmp;
      if (i == 0)
	pixelColor(ecran, vx[t], vy[t], 0x3a3affff);
      if (t > 5)
	lineColor(ecran, vx[t - 1], vy[t - 1], vx[t], vy[t], 0x3a3affff);
      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 100, 25));
      // polygonColor(ecran, vx, vy, 1000, 0xffa02aff);
      // SDL_BlitSurface(rectangle, NULL, ecran, &position);
      i++;
    }
  SDL_Flip(ecran);
}

void	draw_legend(SDL_Surface *ecran)
{
  rectangleColor(ecran, 1000, 400, 850, 450, 0xffffffff);
  lineColor(ecran, 857, 425, 893, 425, 0x3a3affff);
  stringColor(ecran, 900, 422, "Repartition", 0xffffffff);
  stringColor(ecran, (WIN_WIDTH / 2), (WIN_HEIGHT - 30), "QI", 0xffffffff);
  SDL_Flip(ecran);
}
