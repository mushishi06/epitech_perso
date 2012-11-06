/*
** kongjump2.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r/etape_2
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Mar  4 19:44:11 2012 belia-_r
** Last update Sun Mar  4 19:44:45 2012 belia-_r
*/
#include "epikong.h"

char		jmp(int x, int y, char c, char **map, t_pict *pict)
{
  char		sauv;

  sauv = map[x - 1][y];
  map[x - 1][y] = 'b';
  map[x][y] = c;
  draw_map(map, pict);
  SDL_Flip(pict->win);
  usleep(3000);
  c = map[x - 2][y];
  map[x - 2][y] = 'b';
  map[x - 1][y] = sauv;
  aff_win(map, pict);
  usleep(3000);
  sauv = map[x][y];
  map[x][y] = 'i';
  map[x - 2][y] = c;
  return (sauv);
}

char		kongjump(char **map, char c, t_pict *pict)
{
  int           x, y;
  char          sauv = c;

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
  if (map[x - 1][y] != 'w' && map[x - 2][y] != 'w')
    sauv = jmp(x, y, c, map, pict);
  return (sauv);
}

char		kongjumpright_1(int x, int y, char c, char **map, t_pict *pict)
{
  char		sauv;

  sauv = map[x - 1][y + 2];
  map[x - 1][y + 2] = 'j';
  map[x - 1][y + 1] = c;
  usleep(500);
  aff_win(map, pict);
  if (map[x - 1][y + 3] != 'w' || map[x - 1][y + 3] == 'k')
    {
      c = map[x - 1][y + 3];
      map[x - 1][y + 3] = 'j';
      map[x - 1][y + 2] = sauv;
      usleep(500);
      aff_win(map, pict);
      if (map[x][y + 3] != 'w' || map[x][y + 3] == 'k')
	{
	  sauv = map[x][y + 3];
	  map[x][y + 3] = 'j';
	  map[x - 1][y + 3] = c;
	}
      else
	sauv = c;
    }
  return (sauv);
}

char		kongjumpright_2(int x, int y, char c, char **map, t_pict *pict)
{
  char		sauv;

  sauv = map[x - 1][y];
  map[x - 1][y] = 'j';
  map[x][y] = c;
  usleep(500);
  aff_win(map, pict);
  if (map[x - 1][y + 1] != 'w' || map[x - 1][y + 1] == 'k')
    {
      c = map[x - 1][y + 1];
      map[x - 1][y + 1] = 'j';
      map[x - 1][y] = sauv;
      usleep(500);
      aff_win(map, pict);
      if (map[x - 1][y + 2] != 'w' || map[x - 1][y + 2] == 'k')
	sauv = kongjumpright_1(x, y, c, map, pict);
      else
	sauv = c;
    }
  return (sauv);
}

char		kongjumpright(char **map, char c, t_pict *pict)
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
  if (map[x - 1][y] != 'w' || map[x -1][y] == 'k')
    sauv = kongjumpright_2(x, y, c, map, pict);
  if (sauv == 'o' && (check_end(map) == 1))
    donkey_win(pict->win);
  fall(map, pict);
  if (sauv == 'n' || sauv == 'm' || sauv == 'k')
    {
      if (c != 's')
	sauv = '.';
    }
  return (sauv);
}
