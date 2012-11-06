/*
** menu.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r/etape_2
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Mar  4 21:12:40 2012 belia-_r
** Last update Sun Mar  4 22:35:32 2012 belia-_r
*/

#include "epikong.h"

SDL_Surface		*aff_start(SDL_Surface *win)
{
  SDL_Surface	*image;
  SDL_Rect	pos;

  pos.x = 0;
  pos.y = 0;
  image = SDL_LoadBMP("./data/pic/accueil_sans_start.bmp");
  SDL_BlitSurface(image, NULL, win, &pos);
  return (image);
}

SDL_Surface		*aff_press(SDL_Surface *win)
{
  SDL_Surface	*press;
  SDL_Rect	pos;

  pos.x = 50;
  pos.y = 540;
  press = IMG_Load("./data/pic/press_start.png");
  SDL_BlitSurface(press, NULL, win, &pos);
  return (press);
}

void		wait_event(SDL_Surface *win, SDL_Surface *start,
			   SDL_Surface *press)
{
  SDL_Event	event;

  (void)win;
  SDL_PollEvent(&event);
  switch (event.type)
    {
    case SDL_QUIT:
      SDL_FreeSurface(press);
      SDL_FreeSurface(start);
      SDL_FreeSurface(win);
      exit(0);
    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_ESCAPE)
	exit(-1);
      else
	aff_new_content(1, win);
      break;
    default: break;
    }
}

int		launch_loop(SDL_Surface *win, SDL_Surface *start,
			    SDL_Surface *press, int visible)
{
  unsigned int	t;

  t = get_ms();
  while (1)
    {
      if (get_ms() > t + 500)
	{
	  t = get_ms();
	  if (visible == 1)
	    {
	      visible = 0;
	      SDL_FreeSurface(press);
	      SDL_FreeSurface(start);
	      start = aff_start(win);
	    }
	  else
	    {
	      visible = 1;
	      press = aff_press(win);
	    }
	  SDL_Flip(win);
	}
      wait_event(win, start, press);
      usleep(500);
    }
}

int		launch_menu(SDL_Surface *win)
{
  SDL_Surface	*start;
  SDL_Surface	*press;
  int		visible;

  start = aff_start(win);
  press = aff_press(win);
  SDL_Flip(win);
  visible = 1;
  launch_loop(win, start, press, visible);
  return (0);
}
