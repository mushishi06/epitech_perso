/*
** fall.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r/etape_3
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Mar  4 20:43:47 2012 belia-_r
** Last update Sun Mar  4 20:43:48 2012 belia-_r
*/

#include "epikong.h"

int		check_block(char **map, int x, int y)
{
  while (map[x + 1][y] == '.' || map[x + 1][y] == 'k')
    x++;
  return (x);
}

void	check_fall(int x, int y, int k, char **map, t_pict *pict)
{
  if (x > k)
    x = k;
  map[x][y] = 'i';
  if (map[x + 1][y] == 'o' && (check_end(map) == 1))
    donkey_win(pict->win);
  aff_win(map, pict);
  usleep(80000);
  game_over(pict->win);
}

void	fall_kong(char **map, int x, int y, t_pict *pict)
{
  int		j;
  int		k;
  int		xtmp;

  xtmp = x;
  j = 1;
  k = 0;
  k = check_block(map, x, y);
  while (x < k)
    {
      map[x][y] = '.';
      x = x + j;
      if (x > k)
	x = k;
      map[x][y] = 'i';
      usleep(50000);
      aff_win(map, pict);
      if (j == 1)
	j = 2;
      else
	j = j * j;
    }
  if ((x - xtmp) > 4)
    check_fall(x, y, k, map, pict);
}

void		fall(char **map, t_pict *pict)
{
  int		x, y;

  x = 0;
  y = 0;
  while (map[x][y] != 'i' && map[x][y] != 'j')
    {
      if (map[x][y] == '\n')
	{
	  y = 0;
	  x++;
	}
      y++;
    }
  if (map[x + 1][y] == '.' || map[x + 1][y] == 'k')
    fall_kong(map, x, y, pict);
  SDL_Flip(pict->win);
}
