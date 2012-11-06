/*
** aff_info.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sat Mar  3 14:00:55 2012 belia-_r
** Last update Sun Mar  4 19:24:36 2012 belia-_r
*/

#include "epikong.h"

void		aff_inf(SDL_Surface *win)
{
  SDL_Surface *heart;
  SDL_Surface	*empty;
  SDL_Rect	pos;
  int		i;

  pos.x = 0;
  pos.y = win->h - 30;
  heart = SDL_LoadBMP("./data/pic/heart.bmp");
  empty = SDL_LoadBMP("./data/pic/empty_sprite.bmp");
  for (i = 0; i < 35; i++)
    {
      SDL_BlitSurface(empty, NULL, win, &pos);
      pos.x += 30;
    }
  i = life(win, 0, NULL, '.');
  pos.x = win->w - 30;
  while (i > 0)
    {
      SDL_BlitSurface(heart, NULL, win, &pos);
      pos.x -= 30;
      i--;
    }
}
