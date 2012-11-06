/*
** run.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sat Mar  3 13:18:54 2012 belia-_r
** Last update Sat Mar  3 14:24:38 2012 belia-_r
*/

#include "epikong.h"

int		run(int argc, char **argv)
{
  SDL_Surface	*win;
  int		*length;
  int		*height;
  char		**map;
  t_pict	*pict;

  length = malloc(sizeof(*length));
  height = malloc(sizeof(*height));
  if (argc != 2 && argc != 1)
    return (-1);
  if (argc > 1)
    {
      part_type = 0;
      if ((map = parse(argv[1], length, height)) == NULL)
	return (-1);
      (*length)--;
      win = create_win((*length * SPRITE_LENGTH),
		       ((*height * SPRITE_HEIGHT)));
      pict = create_pict();
      main_loop(map, win, pict);

    }
  return (0);
}

void		main_loop(char **map, SDL_Surface *win, t_pict *pict)
{
  SDL_Surface	*rect;
  SDL_Event	event;
  char		c;
  unsigned int	t;

  c = '.';
  rect = SDL_CreateRGBSurface
    (SDL_HWSURFACE, SPRITE_LENGTH, SPRITE_HEIGHT, 32, 0, 0, 0, 0);
  draw_map(map, win, pict, rect);
  SDL_Flip(win);
  while (c != 0)
    {
      draw_map(map, win, pict, rect);
      SDL_Flip(win);
      SDL_PollEvent(&event);
      if (event.type == SDL_QUIT)
	c = 0;
      usleep(700);
    }
  SDL_FreeSurface(rect);
}
