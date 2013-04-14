/*
** sdl_math.h for sdl_math in /home/belia-_r/afs/epitech_perso/Tech_2/Math/204
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Tue Apr  9 03:08:59 2013 romain belia-bourgeois
** Last update Sun Apr 14 19:28:53 2013 romain belia-bourgeois
*/

#ifndef __SDL_MATH_H_
# define __SDL_MATH_H_

# define WIN_WIDTH	1200
# define WIN_HEIGHT	800
# define OFFSET		80

#include	<SDL/SDL.h>

void	draw_fleche_x(SDL_Surface *ecran, SDL_Surface *rectangle, int fle);
void	draw_fleche_y(SDL_Surface *ecran, SDL_Surface *rectangle, int fle);
void	draw_axe_x(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_x);
void	draw_axe_y(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_y);

void	draw_func_densite(SDL_Surface *ecran, SDL_Surface *rectangle, double a);
double	fonc_test(double a, double b, double h, double n, double p_a, double total);
double	fonc_rep(double a, double b, double p_a);
double	f(double a, double t);

void*	xmalloc(size_t size);
void	Pause();
void	draw_legend(SDL_Surface *ecran);//, SDL_Surface *rectangle, int x, int y)

#endif /* __SDL_MATH_H_ */
