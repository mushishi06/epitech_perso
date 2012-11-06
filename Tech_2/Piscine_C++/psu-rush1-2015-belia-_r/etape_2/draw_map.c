/*
** draw_map.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sat Mar  3 13:33:05 2012 belia-_r
** Last update Sun Mar  4 19:15:15 2012 belia-_r
*/

#include "epikong.h"

void		draw_sprite(char c, t_pict *pict)
{
  (void)pict->rect;
  if (c == 'w')
    SDL_BlitSurface(pict->wall, NULL, pict->win, &pict->pos);
  else if (c == 's')
    SDL_BlitSurface(pict->scale, NULL, pict->win, &pict->pos);
  else if (c == 'm')
    SDL_BlitSurface(pict->mob_left, NULL, pict->win, &pict->pos);
  else if (c == 'n')
    SDL_BlitSurface(pict->mob_right, NULL, pict->win, &pict->pos);
  else if (c == 'o')
    SDL_BlitSurface(pict->door, NULL, pict->win, &pict->pos);
  else if (c == 'i')
    SDL_BlitSurface(pict->donkey_left, NULL, pict->win, &pict->pos);
  else if (c == 'j')
    SDL_BlitSurface(pict->donkey_right, NULL, pict->win, &pict->pos);
  else if (c == '.')
    SDL_BlitSurface(pict->empty, NULL, pict->win, &pict->pos);
  else if (c == 'k')
    SDL_BlitSurface(pict->key, NULL, pict->win, &pict->pos);
  else if (c == 'b')
    SDL_BlitSurface(pict->donkey_jump, NULL, pict->win, &pict->pos);
}

int	draw_map(char **wtab, t_pict *pict)
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
	  draw_sprite(wtab[i][j], pict);
	  x += SPRITE_LENGTH;
	}
      x = 0;
      j = 0;
      y += SPRITE_HEIGHT;
    }
  aff_inf(pict->win);
  return (0);
}
