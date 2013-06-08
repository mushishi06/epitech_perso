/*
** fonctions.c for 205Qi in /home/belia-_r/afs/epitech_perso/Tech_2/Math/205
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Sun May  5 12:51:16 2013 romain belia-bourgeois
** Last update Sun Jun  2 23:25:13 2013 romain belia-bourgeois
*/

#include	<SDL/SDL_gfxPrimitives.h>
#include	<math.h>
#include	"sdl_math.h"

void	draw_legend(SDL_Surface *ecran)
{
  rectangleColor(ecran, 1000, 400, 850, 450, 0xffffffff);
  lineColor(ecran, 857, 425, 893, 425, 0x3a3affff);
  stringColor(ecran, 900, 422, "ajustement X sur Y", 0xffffffff);
  stringColor(ecran, (WIN_WIDTH / 2), (WIN_HEIGHT - 30), "bob", 0xffffffff);
  SDL_Flip(ecran);
}
