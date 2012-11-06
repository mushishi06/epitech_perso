/*
** index.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r/etape_2
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Mar  4 21:59:37 2012 belia-_r
** Last update Sun Mar  4 22:05:20 2012 belia-_r
*/

#include "epikong.h"

SDL_Surface		*aff_img(SDL_Surface *win)
{
  SDL_Surface   *image;
  SDL_Rect      pos;

  pos.x = 0;
  pos.y = 0;
  image = SDL_LoadBMP("./data/pic/menu.bmp");
  SDL_BlitSurface(image, NULL, win, &pos);
  return (image);
}
