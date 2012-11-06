/*
** index_content.c for epikonk in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r/etape_2
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Mar  4 21:24:52 2012 belia-_r
** Last update Sun Mar  4 22:38:05 2012 belia-_r
*/

#include "epikong.h"

void		load_level(int level)
{
  char		**map;
  t_pict	*pict;
  int		*length;
  int		*height;

  length = malloc(sizeof(*length));
  height = malloc(sizeof(*height));
  if (level == 1)
    map = parse("./data/map_1.txt", length, height);
  else if (level == 2)
    map = parse("./data/map_2.txt", length, height);
  else if (level == 3)
    map = parse("./data/map_3.txt", length, height);
  else if (level == 4)
    map = parse("./data/map_4.txt", length, height);
  else
    map = parse("./data/map_5.txt", length, height);
  (*length)--;
  pict = create_pict();
  pict->win = create_win((*length * SPRITE_LENGTH),
			 ((*height * SPRITE_HEIGHT) + SPRITE_HEIGHT));
  if (part_type == 1)
    part_type = level;
  else
    part_type = level + 10;
  main_loop(map, pict);
}

void		choose_map(SDL_Surface *win, TTF_Font *police, SDL_Color red,
			   SDL_Rect pos, SDL_Surface *texte)
{
  SDL_Surface *num;
  SDL_Event	event;
  int		n;
  SDL_Rect pos2;
  SDL_Surface	*image;

  image = aff_img(win);
  n = 1;
  pos2.x = 550;
  pos2.y = 542;
  num = TTF_RenderText_Blended(police, "   1 ->", red);
  SDL_BlitSurface(texte, NULL, win, &pos);
  SDL_BlitSurface(num, NULL, win, &pos2);
  SDL_Flip(win);
  while (1)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
	{
	case SDL_QUIT:
	  exit(0);
	  break;
	case SDL_KEYDOWN:
	  switch(event.key.keysym.sym)
            {
            case SDLK_LEFT:
	      if (n != 1)
		n--;
              break;
            case SDLK_RIGHT:
	      if (n != 5)
		n++;
              break;
	    case SDLK_ESCAPE:
	      SDL_FreeSurface(win);
	      exit(EXIT_FAILURE);
	      break;
            default:
	      SDL_FreeSurface(win);
	      load_level(n);
	      return ;
	      break;
	    }
	}
      SDL_FreeSurface(num);
      SDL_FreeSurface(image);
      image = aff_img(win);
      num = TTF_RenderText_Blended(police, "   1 ->", red);
      if (n == 1)
	num = TTF_RenderText_Blended(police, "   1 ->", red);
      if (n == 2)
	num = TTF_RenderText_Blended(police, "<- 2 ->", red);
      if (n == 3)
	num = TTF_RenderText_Blended(police, "<- 3 ->", red);
      if (n == 4)
	num = TTF_RenderText_Blended(police, "<- 4 ->", red);
      if (n == 5)
	num = TTF_RenderText_Blended(police, "<- 5   ", red);
      SDL_BlitSurface(num, NULL, win, &pos2);
      SDL_BlitSurface(texte, NULL, win, &pos);
      SDL_Flip(win);
    }
}

void		aff_choose_map(SDL_Surface *win)
{
  SDL_Rect pos;
  SDL_Surface *texte;
  TTF_Font *police;
  SDL_Color red;

  red.r = 255;
  red.g = 0;
  red.b = 0;
  if (TTF_Init() == -1)
    {
      fprintf(stderr,
	      "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
      exit(EXIT_FAILURE);
    }
  pos.x = 250;
  pos.y = 540;
  police = TTF_OpenFont("./times.ttf", 30);
  texte = TTF_RenderText_Blended(police, "Choississez votre map :", red);
  choose_map(win, police, red, pos, texte);
  TTF_CloseFont(police);
  TTF_Quit();
}

void		aff_new_content(int content, SDL_Surface *win)
{
  SDL_Surface	*image;

  image = aff_img(win);
  image = image;
  if (content == 1)
    {
      part_type = 1;
      aff_choose_map(win);
    }
  else if (content == 2)
    {
      part_type = 0;
      aff_choose_map(win);
    }
  else if (content == 3)
    {
      launch_menu(win);
    }
  else
    exit(0);
}
