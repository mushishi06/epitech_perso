/*
** others2.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r/etape_2
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Mar  4 19:03:44 2012 belia-_r
** Last update Sun Mar  4 21:43:19 2012 belia-_r
*/

#include "epikong.h"

void			game_over(SDL_Surface *win)
{
  SDL_Surface           *n_win;
  SDL_Surface		*game_over;
  SDL_Rect		pos;

  pos.x = (win->w / 2) - 240;
  pos.y = (win->h / 2) - 180;
  game_over = SDL_LoadBMP("./data/pic/game_over.bmp");
  SDL_BlitSurface(game_over, NULL, win, &pos);
  SDL_Flip(win);
  sleep(3);
  SDL_FreeSurface(win);
  n_win = create_win(900, 730);
  launch_menu(n_win);
  g_quit = 1;
}

void		restart(char **map)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (map[x] != NULL)
    {
      y = 0;
      while (map[x][y] != '\n')
	{
	  y++;
	  if (map[x][y] == 'i' || map[x][y] == 'j')
	    {
	      if (map[x-1][y] == 's')
		map[x][y] = 's';
	      else
		map[x][y] = '.';
	    }
	}
      x++;
    }
  map[x-2][y-2] = 'i';
}

int		life(SDL_Surface *win, int i, char **map, char c)
{
  static int life;

  c = '.';
  c = c;
  if (life == 0 || i == 2)
    life = 3;
  if (i == 1)
    {
      life--;
      if (life == 0)
	game_over(win);
      else
	restart(map);
    }
  return (life);
}

void			donkey_win(SDL_Surface *win)
{
  SDL_Surface           *n_win;
  SDL_Surface		*image;
  SDL_Rect		pos;

  pos.x = (win->w / 2) - 201;
  pos.y = (win->h / 2) - 130;
  image = SDL_LoadBMP("./data/pic/donkey_win.bmp");
  SDL_BlitSurface(image, NULL, win, &pos);
  SDL_Flip(win);
  sleep(3);
  n_win = create_win(900, 730);
  if (part_type == 0 || part_type > 4)
      launch_menu(n_win);
  part_type++;
  load_level(part_type);
}

unsigned int		get_ms()
{
  struct timeval	time;

  gettimeofday(&time, NULL);
  return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
