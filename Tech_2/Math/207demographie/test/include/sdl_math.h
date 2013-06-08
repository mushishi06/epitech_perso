/*
** sdl_math.h for 207demographie in /home/belia-_r/afs/epitech_perso/Tech_2/Math/207demographie
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Sat Jun  1 18:24:41 2013 romain belia-bourgeois
** Last update Sun Jun  2 19:39:59 2013 romain belia-bourgeois
*/

#ifndef __SDL_MATH_H_
# define __SDL_MATH_H_

# define USAGE		"Usage: ./207demographie country_Code [...]\nWith country_Code type \"EUU\""
# define USAGE_ERROR	"Error : type of params country_Code is not valide use for example \"EUU\"."
# define PATH_FILE	"./207demographie_donnees.csv"

# define WIN_WIDTH	1200
# define WIN_HEIGHT	800
# define OFFSET_H	7
# define OFFSET_W	5

#define MAX 100

#include	<SDL/SDL.h>
#include	<stdbool.h>

typedef struct s_country
{
  char		*country_Name;
  char		*country_Code;
  float		country_nb[52];
} t_country;


extern t_country	data[];

/*
typedef struct s_country
{
  int		nb;
  char		*country_Name;
  char		*country_Code;
  double	*country_nb;
} t_country;
*/
typedef struct s_donnes
{
  char		*name;
  int		num_line;
} t_donnes;

int	xopen(char *pathname, int flag);
int	xfclose(FILE *fp);
char    *get_next_line(int fd);

bool	open_path(char *path);

float	calc_a(float taby[], float tabx[], int nb);
float	calc_b(float taby[], float tabx[], int nb);
void RegLineaire(double x[], double y[], int n, double *a, double *b);


void	draw_fleche_x(SDL_Surface *ecran, SDL_Surface *rectangle, int fle);
void	draw_fleche_y(SDL_Surface *ecran, SDL_Surface *rectangle, int fle);
void	draw_axe_x(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_x);
void	draw_axe_y(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_y);
void	draw_lgd_x(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_x);
void	draw_lgd_y(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_y, int py);
void	draw_lgd(SDL_Surface *ecran);

double	gauss(double ect, double u, double i);
void	draw_func_rep(SDL_Surface *ecran, SDL_Surface *rectangle, double ect, double u);

void*	xmalloc(size_t size);
void	Pause();
void	draw_legend(SDL_Surface *ecran);//, SDL_Surface *rectangle, int x, int y)

#endif /* __SDL_MATH_H_ */
