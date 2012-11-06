/*
** epikong.h for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r/etape_2
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Mar  4 14:11:20 2012 belia-_r
** Last update Sun Mar  4 21:45:13 2012 belia-_r
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

# define UP(key)	(((key[SDLK_UP] == 1) || key[SDLK_w] == 1) ? 1 : 0)
# define JUMP(key)	(((key[SDLK_UP] == 1) || key[SDLK_SPACE] == 1) ? 1 : 0)
# define DOWN(key)	(((key[SDLK_DOWN] == 1) || key[SDLK_s] == 1) ? 1 : 0)
# define RIGHT(key)	(((key[SDLK_RIGHT] == 1) || key[SDLK_a] == 1) ? 1 : 0)
# define LEFT(key)	(((key[SDLK_LEFT] == 1) || key[SDLK_d] == 1) ? 1 : 0)
# define JUMPRIGHT(key)	((((key[SDLK_RIGHT] == 1) && (key[SDLK_SPACE] == 1)) || key[SDLK_e] == 1) ? 1 : 0)
# define JUMPLEFT(key)	((((key[SDLK_LEFT] == 1) && (key[SDLK_SPACE] == 1)) || key[SDLK_q] == 1) ? 1 : 0)

int		part_type;

typedef struct	s_pict
{
  SDL_Rect	pos;

  SDL_Surface	*win;
  SDL_Surface	*rect;
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
/*
  typedef struct s_Input
  {
  char key[SDLK_LAST];
  char quit;
  } t_Input;
*/

char	g_quit;

/**************/
/* Prototypes */
/**************/

char		move_kong_right(char **map, int x, int y, char c);
void            aff_win(char **map, t_pict *pict);
char		checkEvents(t_pict *pict, char **map, char c);
int		run(char *str);
char		**parse(char *file, int *length, int *height);
FILE		*open_map(char *str);
SDL_Surface	*create_win(int length, int heigth);
t_pict		*create_pict();
int		draw_map(char **map, t_pict *pict);
void		draw_sprite(char c, t_pict *pict);
void		main_loop(char **map, t_pict *pict);
char		*launch_mob(char *str, char **map, t_pict *pict, unsigned int *t);
char		kongleft(char **map, char c, t_pict *pict);
char            kongright(char **map, char c, t_pict *pict);
char            kongup(char **map, char c, t_pict *pict);
char            kongdown(char **map, char c, t_pict *pict);
char		*move_mob(char *str, char **map, t_pict *pict);
char		*get_mob(char **map);
unsigned int	get_ms();
void		game_over(SDL_Surface *win);
void		donkey_win(SDL_Surface *win);
void		fall(char **map, t_pict *pict);
char            kongjump(char **map, char c, t_pict *pict);
char            kongjumpright(char **map, char c, t_pict *pict);
char            kongjumpleft(char **map, char c, t_pict *pict);
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

void		load_level(int level);
void		put_black(char **map);
int		life(SDL_Surface *win, int i, char **map, char c);
void		aff_new_content(int content, SDL_Surface *win);
char		*choosefile(int f);
void		aff_inf(SDL_Surface *win);
void		aff_user(SDL_Surface *win);
void		aff_score(SDL_Surface *win);

#endif
