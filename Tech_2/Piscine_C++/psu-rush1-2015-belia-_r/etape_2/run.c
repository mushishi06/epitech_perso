/*
** run.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sat Mar  3 13:18:54 2012 belia-_r
** Last update Sun Mar  4 20:19:44 2012 belia-_r
*/

#include "epikong.h"

void		aff_win(char **map, t_pict *pict)
{
  draw_map(map, pict);
  SDL_Flip(pict->win);
}
char            *get_mob(char **map)
{
  int           i;
  int           j;
  int           nbmob;
  char          *mob;

  nbmob = 0;
  for (j = 0; map[j] != NULL; j++)
    for (i = 0; map[j][i] != '\0'; i++)
      {
	if (map[j][i] == 'm' || map[j][i] == 'n')
	  nbmob++;
      }
  i = 0;
  mob = malloc(sizeof(*mob) * ((2 * nbmob) + 1));
  while (nbmob != 0)
    {
      mob[i] = 'l';
      i++;
      mob[i] = '.';
      i++;
      nbmob--;
    }
  mob[i] = '\0';
  return (mob);
}

int		run(char *str)
{
  int		*length;
  int		*height;
  char		**map;
  t_pict	*pict;

  length = malloc(sizeof(*length));
  height = malloc(sizeof(*height));
  part_type = 0;
  if ((map = parse(str, length, height)) == NULL)
    return (-1);
  (*length)--;
  pict = create_pict();
  pict->win = create_win((*length * SPRITE_LENGTH),
			 ((*height * SPRITE_HEIGHT) + SPRITE_HEIGHT));
  main_loop(map, pict);
  return (0);
}

void		init_rect(t_pict *pict)
{
  pict->rect = SDL_CreateRGBSurface
    (SDL_HWSURFACE, SPRITE_LENGTH, SPRITE_HEIGHT, 32, 0, 0, 0, 0);
}

void		main_loop(char **map, t_pict *pict)
{
  unsigned int	t;
  char		*mob;
  char		c;

  c = '.';
  mob = get_mob(map);
  init_rect(pict);
  aff_win(map, pict);
  t = get_ms();
  life(pict->win, 2, map, c);
  while (g_quit == 0)
    {
      launch_mob(mob, map, pict, &t);
      aff_win(map, pict);
      c = checkEvents(pict, map, c);
      usleep(45000);
    }
  SDL_FreeSurface(pict->rect);
}
