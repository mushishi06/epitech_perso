/*
** main.c for 205Qi in /home/belia-_r/afs/epitech_perso/Tech_2/Math/205
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Sun May  5 12:51:02 2013 romain belia-bourgeois
** Last update Sun May  5 13:40:08 2013 romain belia-bourgeois
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

void	run_option_1(double ect, double u)
{
  SDL_Surface	*ecran = NULL, *rectangle = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }
  ecran = SDL_SetVideoMode(WIN_WIDTH, WIN_HEIGHT, 32, SDL_HWSURFACE| SDL_DOUBLEBUF);
  if (ecran == NULL)
    {
      fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 1,2, 32, 0, 0, 0, 0);
  SDL_WM_SetCaption("205 Qi 2013 Belia-_r", NULL);
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 12,2,45));
  draw_legend(ecran);
  draw_lgd(ecran);
  draw_axe_x(ecran, rectangle, WIN_HEIGHT - 50);
  draw_lgd_x(ecran, rectangle, WIN_HEIGHT - 50);
  draw_axe_y(ecran, rectangle, 50);
  draw_lgd_y(ecran, rectangle, 50, 25);
  draw_fleche_x(ecran, rectangle, WIN_HEIGHT - 50);
  draw_fleche_y(ecran, rectangle, 50);
  draw_func_rep(ecran, rectangle, ect, u);
  Pause();
  SDL_FreeSurface(rectangle);
  SDL_Quit();
}

void	run_option_2(double ect, double u, double qi)
{
  double	t;
  double	tmp = 0;

  for (t = 0; t < qi; (t += 0.01))
    {
      tmp += gauss(ect, u, t);
    }
  printf ("%.1f%% des personnes ont un QI inférieur à %d\n", tmp, (int)qi);
}

void	run_option_3(double ect, double u, double qi_min, double qi_max)
{
  double	t;
  double	tmp = 0;

  for (t = qi_min; t < qi_max; (t += 0.01))
    {
      tmp += gauss(ect, u, t);
    }
  printf ("%.1f%% des personnes ont un QI compris entre %d et %d\n",
	  tmp, (int)qi_min, (int)qi_max);
}

int	main(int argc, char *argv[])
{
  double	ect, u, qi, qi_max;

  if (argc == 3)
    {
      u = atof(argv[1]);
      ect = atof(argv[2]);
      if (u < 0 || u > 200)
	return (EXIT_FAILURE);
      run_option_1(ect, u);
    }
  else if (argc == 4)
    {
      u = atof(argv[1]);
      ect = atof(argv[2]);
      qi = atof(argv[3]);
      if ((u < 0 || u > 200) || (qi < 0 || qi > 200))
	return (EXIT_FAILURE);
      run_option_2(ect, u, qi);
    }
  else if (argc == 5)
    {
      u = atof(argv[1]);
      ect = atof(argv[2]);
      qi = atof(argv[3]);
      qi_max = atof(argv[4]);
      if ((u < 0 || u > 200) || (qi < 0 || qi > 200) ||
	  (qi_max < 0 || qi_max > 200) || (qi > qi_max))
	return (EXIT_FAILURE);
      run_option_3(ect, u, qi, qi_max);
    }
  return EXIT_SUCCESS;
}
