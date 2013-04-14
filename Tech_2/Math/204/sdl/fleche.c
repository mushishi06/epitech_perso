/*
** fleche.c for sdl in /home/belia-_r/afs/epitech_perso/Tech_2/Math/204
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Tue Apr  9 02:35:45 2013 romain belia-bourgeois
** Last update Tue Apr  9 03:23:30 2013 romain belia-bourgeois
*/

#include	"sdl_math.h"

void		draw_fleche_y(SDL_Surface *ecran, SDL_Surface *rectangle, int fle)
{
  //fle = 500
  int		a;
  SDL_Rect	position;

  for (a = (fle - 10); a < fle; a++)
    {
      position.x = a;
      position.y = fle - a;
      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
      SDL_BlitSurface(rectangle, NULL, ecran, &position);
    }
  for (a = fle; a < (fle + 10); a++)
    {
      position.x = a;
      position.y = a - fle;
      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
      SDL_BlitSurface(rectangle, NULL, ecran, &position);
    }

}

void		draw_fleche_x(SDL_Surface *ecran, SDL_Surface *rectangle, int fle)
{
  //fle = 300
  int		a;
  SDL_Rect	position;

  for (a = WIN_WIDTH; a > (WIN_WIDTH - 10); a--)
    {
      position.x = a;
      position.y = fle + WIN_WIDTH - a ;
      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
      SDL_BlitSurface(rectangle, NULL, ecran, &position);
    }
  for (a = (WIN_WIDTH - 10); a < WIN_WIDTH; a++)
    {
      position.x = a;
      position.y = (fle - 10) + a - (WIN_WIDTH - 10);
      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
      SDL_BlitSurface(rectangle, NULL, ecran, &position);
    }
}
