/*
** eventskong2.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r/etape_3
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Mar  4 20:44:02 2012 belia-_r
** Last update Sun Mar  4 21:15:15 2012 belia-_r
*/

#include "epikong.h"

int		check_end(char **map)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (map[y] != NULL)
    {
      while (map[y][x] != '\0')
	{
	  if (map[y][x] == 'k')
	    return (0);
	  x++;
	}
      x = 0;
      y++;
    }
  return (1);
}

void		put_black(char **map)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (map[x + 2] != NULL)
    x++;
  while (map[x][y + 2] != '\n')
    y++;
  map[x][y] = '.';
}

char		move_kong_left(char **map, int x, int y, char c)
{
  char		sauv;

  sauv = map[x][y - 1];
  map[x][y - 1] = 'i';
  if (c == 'k')
    map[x][y] = '.';
  else
    map[x][y] = c;
  return (sauv);
}

char		kongleft(char **map, char c, t_pict *pict)
{
  int		x, y;
  char		sauv = c;

  x = 0;
  y = 0;
  while (map[x][y] != 'i' && map[x][y] != 'j') {
    if (map[x][y] == '\n')
      {
	y = 0;
	x++;
      }
    y++;
  }
  if (map[x][y - 1] == 'o' && (check_end(map) == 1))
    donkey_win(pict->win);
  if (map[x][y - 1] == '.' || map[x][y - 1] == 's' || map[x][y - 1] == 'k')
    sauv = move_kong_left(map, x, y, c);
  if (map[x][y - 1] == 'm' || map[x - 1][y] == 'n')
    life(pict->win, 1, map, c);
  aff_win(map, pict);
   return (sauv);
}

char		move_kong_right(char **map, int x, int y, char c)
{
  char		sauv;

  if (map[x][y + 1] == 'w')
    sauv = '.';
  else
    sauv = map[x][y + 1];
  map[x][y + 1] = 'j';
  if (c == 'k')
    map[x][y] = '.';
  else
    map[x][y] = c;
  return (sauv);
}
