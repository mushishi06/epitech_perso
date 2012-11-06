/*
** checkEvents.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r/etape_2
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sat Mar  3 20:16:49 2012 belia-_r
** Last update Sun Mar  4 22:21:11 2012 belia-_r
*/

#include	"epikong.h"

char	checkEvents(t_pict *pict, char **map, char c)
{
  SDL_Surface           *n_win;
  SDL_Event     event;

  SDL_PollEvent(&event);
  switch (event.type)
    {
    case SDL_QUIT:
      exit(0);
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
	  SDL_FreeSurface(pict->win);
	  n_win = create_win(900, 730);
	  aff_new_content(1, n_win);
	  break;
	case SDLK_a:
	  SDL_Delay(20);
	  SDL_PollEvent(&event);
	  if (event.key.keysym.sym == SDLK_SPACE)
	    c = kongjumpleft(map, c, pict);
	  else
	    c = kongleft(map, c, pict);
	  break;
	case SDLK_d:
	  SDL_Delay(20);
	  SDL_PollEvent(&event);
	  if (event.key.keysym.sym == SDLK_SPACE)
	    c = kongjumpright(map, c, pict);
	  else
	    c = kongright(map, c, pict);
	  break;
	case SDLK_w:
	  c = kongup(map, c, pict);
	  break;
	case SDLK_SPACE:
	  SDL_PollEvent(&event);
	  if (event.key.keysym.sym == SDLK_d)
	    c = kongjumpleft(map, c, pict);
	  else if (event.key.keysym.sym == SDLK_a)
	    c = kongjumpright(map, c, pict);
	  else
	    c = kongjump(map, c, pict);
	  break;
	case SDLK_s:
	  c = kongdown(map, c, pict);
	  break;
	case SDLK_q:
	  c = kongjumpleft(map, c, pict);
	  break;
	case SDLK_e:
	  c = kongjumpright(map, c, pict);
	  break;
	default: break;
	}
    default: break;
    }
  return (c);
}
