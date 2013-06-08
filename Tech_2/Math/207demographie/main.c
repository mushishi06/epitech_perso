/*
** main.c for 207demographie in /home/belia-_r/afs/epitech_perso/Tech_2/Math/207demographie
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Sat Jun  1 18:25:06 2013 romain belia-bourgeois
** Last update Sun Jun  2 23:31:45 2013 romain belia-bourgeois
*/
/*
  #include        <string>
  #include        <sstream>
  #include        <iostream>
*/
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

SDL_Surface	*run_graph(SDL_Surface	*ecran, SDL_Surface *rectangle)
{
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
  SDL_WM_SetCaption("207demographie 2013 Belia-_r", NULL);
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 12,2,45));
  draw_legend(ecran);
  draw_lgd(ecran);
  draw_axe_x(ecran, rectangle, WIN_HEIGHT - 50);
  draw_lgd_x(ecran, rectangle, WIN_HEIGHT - 50);
  draw_axe_y(ecran, rectangle, 50);
  draw_lgd_y(ecran, rectangle, 50, 25);
  draw_fleche_x(ecran, rectangle, WIN_HEIGHT - 50);
  draw_fleche_y(ecran, rectangle, 50);
  return ecran;
}

void	exit_free(int argc, t_donnes *count_code, double *tab_yy)
{
  while (argc - 1 >= 0)
    {
      free(count_code[argc - 1].name);
      argc--;
    }
  free(count_code);
  if (tab_yy)
    free(tab_yy);
}

int	main(int argc, char *argv[])
{
  SDL_Surface	*ecran = NULL, *rectangle = NULL;
  double	a = 0, b = 0, ecty = 0;
  double	*tab_x = NULL, *tab_y = NULL;
  double	*tab_yy = NULL;
  int		i = 0, j = 0, z = 0;
  t_donnes	*count_code = NULL;

  //   system("wget http://belia-bourgeois.com/207demographie_donnees.csv -q");
  // sleep(1);
  if (argc > 1)
    {
      ecran = run_graph(ecran, rectangle);
      count_code = (t_donnes *)malloc((argc) * sizeof(* count_code));
      count_code[argc - 1].name = NULL;
      while (i < (argc - 1))
	{
	  if (strlen(argv[i + 1]) == 3)
	    {
	      count_code[i].name = strdup(argv[i + 1]);
	    }
	  else
	    {
	      puts(USAGE_ERROR);
	      exit_free(argc, count_code, tab_yy);
	      return (EXIT_FAILURE);
	    }
	  i++;
	}
      printf ("pays :\n");
      i = 0;
      while (i < (argc - 1))
	{
	  j = 0;
	  while (data[j].country_Code != NULL)
	    {
	      if (strcasecmp(data[j].country_Code, count_code[i].name) == 0)
		{
		  count_code[i].num_line = j;
		  printf ("\t%s\n", data[j].country_Name, count_code[i].num_line);
		  break;
		}
	      j++;
	    }
	  i++;
	}
      tab_yy = xmalloc(51 * sizeof(tab_yy));
      for (z = 0; z < 51; ++z)
	{
	  i = 0;
	  while (i < (argc - 1))
	    {
	      tab_yy[z] += data[count_code[i].num_line].country_nb[z];
	      i++;
	    }
	  tab_yy[z] = tab_yy[z] / (argc - 1);
	}
      printf ("ajustement de X sur Y :\n");
      // tab_y = data[8].country_nb;
      tab_x = data[0].country_nb;
      calcul_coef_ajust(tab_x, tab_yy, 51, &a, &b, &ecty);
      printf ("\tY = %0.2f X %0.2f\n", (a / 1000000), (b / 1000000));
      printf ("\técart-type :\t\t\t%0.2f\n", ecty);
      printf ("\testimation de la population en 2050 : %0.2f\n", (calcul_y(a, b, 2050) / 1000000));
      lineColor(ecran, 857, 400, 893, 400, 0x3a3a3aff);
      lineColor(ecran, 1961/3, (calcul_y(a, b, 1961) / 1000000), 2050/3, (calcul_y(a, b, 2050) / 1000000), 0x11353aff);
      SDL_Flip(ecran);
      printf ("ajustement de Y sur X :\n");
      calcul_coef_ajust(tab_yy, tab_x, 51, &a, &b, &ecty);
      printf ("\tX = %f Y + %0.2f\n", (a), (b));
      printf ("\técart-type :\t\t\t%0.2f\n", ecty);
      printf ("\testimation de la population en 2050 : %0.2f\n", (calcul_y(a, b, 2050) / 1000000));
      Pause();
      SDL_FreeSurface(rectangle);
      SDL_Quit();
      exit_free(argc, count_code, tab_yy);
    }
  else
    puts(USAGE);
  return EXIT_SUCCESS;
}
