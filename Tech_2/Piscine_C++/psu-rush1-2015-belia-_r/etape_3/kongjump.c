/*
** kongjump.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r/etape_2
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Mar  4 16:57:16 2012 belia-_r
** Last update Sun Mar  4 19:45:14 2012 belia-_r
*/

#include	"epikong.h"

char		kongjumpleft_1(int x, int y, char c, char **map, t_pict *pict)
{
  char		sauv;

  sauv = map[x - 1][y - 2];
  map[x - 1][y - 2] = 'i';
  map[x - 1][y - 1] = c;
  usleep(500);
  aff_win(map, pict);
  if (map[x - 1][y - 3] != 'w' || map[x - 1][y - 3] == 'k')
    {
      c = map[x - 1][y - 3];
      map[x - 1][y - 3] = 'i';
      map[x - 1][y - 2] = sauv;
      usleep(500);
      aff_win(map, pict);
      if (map[x][y - 3] != 'w' || map[x][y - 3] == 'k')
	{
	  sauv = map[x][y - 3];
	  map[x][y - 3] = 'i';
	  map[x - 1][y - 3] = c;
	}
      else
	sauv = c;
    }
  return (sauv);
}

char		kongjumpleft_2(int x, int y, char c, char **map, t_pict *pict)
{
  char		sauv;

  sauv = map[x - 1][y];
  map[x - 1][y] = 'i';
  map[x][y] = c;
  usleep(500);
  aff_win(map, pict);
  if (map[x - 1][y - 1] != 'w' || map[x - 1][y - 1] == 'k')
    {
      c = map[x - 1][y - 1];
      map[x - 1][y - 1] = 'i';
      map[x - 1][y] = sauv;
      usleep(500);
      aff_win(map, pict);
      if (map[x - 1][y - 2] != 'w' || map[x - 1][y - 2] == 'k')
	{
	  sauv = kongjumpleft_1(x, y, c, map, pict);
	}
      else
	sauv = c;
    }
  return (sauv);
}

char		kongjumpleft(char **map, char c, t_pict *pict)
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
  if (map[x - 1][y] != 'w' || map[x - 1][y] == 'k')
    sauv = kongjumpleft_2(x, y, c, map, pict);
  if (sauv == 'o' && (check_end(map) == 1))
    donkey_win(pict->win);
  if (sauv == 'n' || sauv == 'm')
    {
      if (c != 's')
	sauv = '.';
    }
  fall(map, pict);
  return (sauv);
}
