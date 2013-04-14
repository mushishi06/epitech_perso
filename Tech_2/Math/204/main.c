/*
** main.c for 204canard in /home/belia-_r/afs/epitech_perso/Tech_2/Math/204
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Fri Apr 12 21:34:28 2013 romain belia-bourgeois
** Last update Sun Apr 14 19:28:01 2013 romain belia-bourgeois
*/

#include        <string>
#include        <sstream>
#include        <iostream>
#include	<stdlib.h>
#include	<stdio.h>
#include	<SDL/SDL.h>
#include	<SDL/SDL_gfxPrimitives.h>
#include	<math.h>
#include	"sdl_math.h"

void	Pause()
{
  SDL_Event	event;
  bool		_exit = false;

  while (!_exit)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
	{
	case SDL_QUIT:
	  _exit = true;
	  break;
	case SDL_KEYDOWN:
	  switch (event.key.keysym.sym)
	    {
	    case SDLK_ESCAPE:
	      _exit = true;
	      break;
	    }
	  break;
	}
    }
}

int	main(int argc, char *argv[])
{
  SDL_Surface	*ecran = NULL, *rectangle = NULL;
  SDL_Rect	position;
  double	a;

  if (argc >= 2)
    {
      a = atof(argv[1]);
      if (a < 0 || a > 2.5)
	return (EXIT_FAILURE);
      if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
	  fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
	  exit(EXIT_FAILURE);
	}
      SDL_WM_SetIcon(SDL_LoadBMP("204_icone.bmp"), NULL);
      ecran = SDL_SetVideoMode(WIN_WIDTH, WIN_HEIGHT, 32, SDL_HWSURFACE| SDL_DOUBLEBUF);
      if (ecran == NULL)
	{
	  fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
	  exit(EXIT_FAILURE);
	}
      rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 1,2, 32, 0, 0, 0, 0);
      SDL_WM_SetCaption("204 Canard 2013 Belia-_r", NULL);
      SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 12,2,45));
      draw_legend(ecran);
      draw_axe_x(ecran, rectangle, WIN_HEIGHT - 50);
      draw_axe_y(ecran, rectangle, 50);
      draw_fleche_x(ecran, rectangle, WIN_HEIGHT - 50);
      draw_fleche_y(ecran, rectangle, 50);
      draw_func_densite(ecran, rectangle, 1.18);
      Pause();
      SDL_FreeSurface(rectangle);
      SDL_Quit();
    }
  return EXIT_SUCCESS;
}
