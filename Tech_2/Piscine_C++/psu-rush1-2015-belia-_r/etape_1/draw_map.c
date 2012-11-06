/*
** draw_map.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sat Mar  3 13:33:05 2012 belia-_r
** Last update Sat Mar  3 18:15:10 2012 belia-_r
*/

#include "epikong.h"

void		draw_sprite(SDL_Surface *win, SDL_Surface *rectangle,
			    char c, t_pict *pict)
{
  (void)rectangle;
  if (c == 'w')
    SDL_BlitSurface(pict->wall, NULL, win, &pict->pos);
  else if (c == 's')
    SDL_BlitSurface(pict->scale, NULL, win, &pict->pos);
  else if (c == 'm')
    SDL_BlitSurface(pict->mob_left, NULL, win, &pict->pos);
  else if (c == 'n')
    SDL_BlitSurface(pict->mob_right, NULL, win, &pict->pos);
  else if (c == 'o')
    SDL_BlitSurface(pict->door, NULL, win, &pict->pos);
  else if (c == 'i')
    SDL_BlitSurface(pict->donkey_left, NULL, win, &pict->pos);
  else if (c == 'j')
    SDL_BlitSurface(pict->donkey_right, NULL, win, &pict->pos);
  else if (c == '.')
    SDL_BlitSurface(pict->empty, NULL, win, &pict->pos);
  else if (c == 'k')
    SDL_BlitSurface(pict->key, NULL, win, &pict->pos);
  else if (c == 'b')
    SDL_BlitSurface(pict->donkey_jump, NULL, win, &pict->pos);
}

int	draw_map(char **wtab, SDL_Surface *win, t_pict *pict, SDL_Surface *rect)
{
  int		x = 0;
  int		y = 0;
  int		i;
  int		j;

  for (i = 0; wtab[i] != NULL; i++)
    {
      for (j = 0; wtab[i][j]; j++)
	{
 	  pict->pos.x = x;
	  pict->pos.y = y;
	  draw_sprite(win, rect, wtab[i][j], pict);
	  x += SPRITE_LENGTH;
	}
      x = 0;
      j = 0;
      y += SPRITE_HEIGHT;
    }
  return (0);
}
