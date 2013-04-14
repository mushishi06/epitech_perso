/*
** axes.c for sdl in /home/belia-_r/afs/epitech_perso/Tech_2/Math/204
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Tue Apr  9 02:35:35 2013 romain belia-bourgeois
** Last update Tue Apr  9 03:34:35 2013 romain belia-bourgeois
*/

#include	"sdl_math.h"

void		draw_axe_x(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_x)
{
  int		a;
  SDL_Rect	position;

  for (a = 0; a < WIN_WIDTH; a++)
    {
      position.x = a;
      position.y = pos_x;
      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
      SDL_BlitSurface(rectangle, NULL, ecran, &position);
    }
}

void		draw_axe_y(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_y)
{
  int		a;
  SDL_Rect	position;


  for (a = 0; a < WIN_HEIGHT; a++)
    {
      position.x = pos_y;
      position.y = a;
      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
      SDL_BlitSurface(rectangle, NULL, ecran, &position);
    }
}
