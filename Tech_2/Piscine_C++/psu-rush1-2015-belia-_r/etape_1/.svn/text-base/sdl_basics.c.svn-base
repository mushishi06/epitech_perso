/*
** sdl_basics.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r/
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sat Mar  3 14:06:35 2012 belia-_r
** Last update Sat Mar  3 14:13:57 2012 belia-_r
*/

#include "epikong.h"

t_pict		*create_pict()
{
  t_pict	*pict;

  pict = malloc(sizeof(*pict));
  pict->pos.x = 0;
  pict->pos.y = 0;
  pict->wall = SDL_LoadBMP("./data/pic/wall_sprite.bmp");
  pict->scale = SDL_LoadBMP("./data/pic/scale_sprite.bmp");
  pict->key = SDL_LoadBMP("./data/pic/key_sprite.bmp");
  pict->door = SDL_LoadBMP("./data/pic/door_sprite.bmp");
  pict->mob_right = SDL_LoadBMP("./data/pic/mob_sprite_right.bmp");
  pict->mob_left = SDL_LoadBMP("./data/pic/mob_sprite_left.bmp");
  pict->donkey_right = SDL_LoadBMP("./data/pic/donkey_sprite_right.bmp");
  pict->donkey_jump = SDL_LoadBMP("./data/pic/jump.bmp");
  pict->donkey_left = SDL_LoadBMP("./data/pic/donkey_sprite_left.bmp");
  pict->empty = SDL_LoadBMP("./data/pic/empty_sprite.bmp");
  return (pict);
}

SDL_Surface	*create_win(int length, int heigth)
{
  SDL_Surface	*win;

  win = SDL_SetVideoMode(length, heigth, PIX_PER_BYTES,
			 SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Epikong 2015", NULL);
  return (win);
}
