/*
** eventskong.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r/etape_2
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Mar  4 15:51:11 2012 belia-_r
** Last update Sun Mar  4 20:48:23 2012 belia-_r
*/

#include "epikong.h"

char		kongright(char **map, char c, t_pict *pict)
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
  if (map[x][y + 1] == 'o' && (check_end(map) == 1))
    donkey_win(pict->win);
  if (map[x][y + 1] == 'm' || map[x][y + 1] == 'n')
    life(pict->win, 1, map, c);
  if (map[x][y + 1] == '.' || map[x][y + 1] == 's' || map[x][y + 1] == 'k')
    sauv = move_kong_right(map, x, y, c);
  fall(map, pict);
  aff_win(map, pict);
  return (sauv);
}

char 		swap_kong_up(char **map, int x, int y, char c)
{
  char		sauv;

  sauv = map[x - 1][y];
  map[x - 1][y] = 'i';
  map[x][y] = c;
  return (sauv);
}

char		kongup(char **map, char c, t_pict *pict)
{
  int		x = 0, y = 0;
  char		sauv = c;

  while (map[x][y] != 'i' && map[x][y] != 'j')
    {
      if (map[x][y] == '\n')
	{
	  y = 0;
	  x++;
	}
      y++;
    }
  if (map[x - 1][y] == 'm' || map[x - 1][y] == 'n')
    game_over(pict->win);
  if (map[x - 1][y] == 'o' && (check_end(map) == 1))
    donkey_win(pict->win);
  if (c == 's' || map[x][y -1] == 'k')
    sauv = swap_kong_up(map, x, y, c);
  if (sauv == 'k')
    sauv = '.';
  aff_win(map, pict);
  return (sauv);
}

char 		swap_kong_down(char **map, int x, int y, char c)
{
  char		sauv;

  sauv = map[x + 1][y];
  map[x + 1][y] = 'i';
  map[x][y] = c;
  return (sauv);
}

char		kongdown(char **map, char c, t_pict *pict)
{
  int		x, y;
  char		sauv = c;

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
  if (map[x + 1][y] == 'm' || map[x - 1][y] == 'n')
    life(pict->win, 1, map, c);
  if (map[x + 1][y] == 'o' && (check_end(map) == 1))
    donkey_win(pict->win);
  if (map[x + 1][y] == 's')
    sauv = swap_kong_down(map, x, y, c);
  if (sauv == 'k')
    sauv = '.';
  aff_win(map, pict);
  return (sauv);
}
