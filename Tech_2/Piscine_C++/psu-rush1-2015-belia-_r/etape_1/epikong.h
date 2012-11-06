/*
** epikong.h for epikong in /home/reboul_a//work/tek2/svn-projet-pitek/Rush/Epikong
**
** Made by anthony reboul
** Login   <reboul_a@epitech.net>
**
** Started on  Sat Mar 26 11:02:24 2011 anthony reboul
** Last update Sat Mar  3 12:00:17 2012 belia-_r
*/

#ifndef __EPIKONG_H__
# define __EPIKONG_H__

/************/
/* Includes */
/************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

/***********/
/* Defines */
/***********/

# define BLACK_COLOR		0x000000
# define WHITE_GREY_COLOR	0x898989
# define BLACK_GREY_COLOR	0x626360
# define ORANGE_COLOR		0xf46621

# define PIX_PER_BYTES	32
# define M_PI		3.14159265358979323846
# define SPRITE_LENGTH	30
# define SPRITE_HEIGHT	30

int		part_type;

typedef struct	s_pict
{
  SDL_Rect	pos;

  SDL_Surface	*wall;
  SDL_Surface	*scale;
  SDL_Surface	*key;
  SDL_Surface	*door;
  SDL_Surface	*mob_right;
  SDL_Surface	*mob_left;
  SDL_Surface	*donkey_right;
  SDL_Surface	*donkey_left;
  SDL_Surface	*donkey_jump;
  SDL_Surface	*empty;
}		t_pict;

/* Exemple : SDL_BlitSurface(wall, NULL, win, &pos) */

int		score;

/**************/
/* Prototypes */
/**************/

int		draw_map(char **map, SDL_Surface *win, t_pict *pict, SDL_Surface *rect);
int		run(int argc, char **argv);
char		**parse(char *file, int *length, int *height);
SDL_Surface	*create_win(int length, int heigth);
void		draw_sprite(SDL_Surface *win, SDL_Surface *rectangle, char c, t_pict *pict);
FILE		*open_map(char *str);
t_pict		*create_pict();
void		main_loop(char **map, SDL_Surface *win, t_pict *pict);
char		kongleft(char **map, char c, SDL_Surface *win, t_pict *pict, SDL_Surface *rect);
char            kongright(char **map, char c, SDL_Surface *win, t_pict *pict, SDL_Surface *rect);
char            kongup(char **map, char c, SDL_Surface *win, t_pict *pict, SDL_Surface *rect);
char            kongdown(char **map, char c, SDL_Surface *win, t_pict *pict, SDL_Surface *rect);
char		*move_mob(char *str, char **map, SDL_Surface *win, SDL_Surface *rect, t_pict *pict);
char		*get_mob(char **map);
unsigned int	get_ms();
void		game_over(SDL_Surface *win);
void		donkey_win(SDL_Surface *win);
void		fall(char **map, SDL_Surface *win, t_pict *pict, SDL_Surface *rect);
char            kongjump(char **map, char c, SDL_Surface *win, t_pict *pict, SDL_Surface *rect);
char            kongjumpright(char **map, char c, SDL_Surface *win, t_pict *pict, SDL_Surface *rect);
char            kongjumpleft(char **map, char c, SDL_Surface *win, t_pict *pict, SDL_Surface *rect);
int		check_end(char **map);
SDL_Surface	*aff_start(SDL_Surface *win);
SDL_Surface	*aff_press(SDL_Surface *win);
void		wait_event();
int		launch_menu(SDL_Surface *win);
void		run_index(SDL_Surface *win);
SDL_Surface	*aff_img(SDL_Surface *win);

SDL_Surface	*aff_black_bt1(SDL_Surface *win);
SDL_Surface	*aff_red_bt1(SDL_Surface *win);
SDL_Surface	*aff_black_bt2(SDL_Surface *win);
SDL_Surface	*aff_red_bt2(SDL_Surface *win);
SDL_Surface	*aff_black_bt3(SDL_Surface *win);
SDL_Surface	*aff_red_bt3(SDL_Surface *win);
SDL_Surface	*aff_black_bt4(SDL_Surface *win);
SDL_Surface	*aff_red_bt4(SDL_Surface *win);

void		put_black(char **map);
int		life(SDL_Surface *win, int i, char **map, char c);
void		aff_new_content(int content, SDL_Surface *win);
FILE		*open_score(char *str);
char		**putintab(char *str);
void		putscoreintxt(char **wtab, int pos, char *name, int score, int f);
int		putscore(char *name, int score, int f);
char		*my_putnbr_base(int fd, int nbr, const char *base);
char		**getscore(int f);
char		*choosefile(int f);
void		aff_inf(SDL_Surface *win);
void		aff_user(SDL_Surface *win);
void		aff_score(SDL_Surface *win);

#endif
