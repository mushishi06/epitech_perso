/*
** move_mob.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r/etape_2
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Mar  4 14:05:26 2012 belia-_r
** Last update Sun Mar  4 19:39:40 2012 belia-_r
*/

#include "epikong.h"

char		*move_left(char *str, int i, int j, int k,
			   char **map, t_pict *pict)
{
  if (map[i][j - 1] != 'w' && map[i + 1][j - 1] != '.'
      && map[i][j - 1] != 'k' && map[i][j - 1] != 'o')
    {
      if (map[i][j - 1] == 'i' || map[i][j - 1] == 'j')
	{
	  life(pict->win, 1, map, '.');
	  kongleft(map, '.', pict);
	  put_black(map);
	  kongright(map, '.', pict);
	}
      map[i][j] = str[k + 1];
      str[k + 1] = map[i][j - 1];
      map[i][j - 1] = 'm';
    }
  else
    {
      str[k] = 'r';
      map[i][j] = 'n';
    }
  return (str);
}

char		*move_right(char *str, int i, int j, int k,
			    char **map, t_pict *pict)
{
  if (map[i][j + 1] != 'w' && map[i + 1][j + 1] != '.'
      && map[i][j + 1] != 'k' && map[i][j + 1] != 'o')
    {
      if (map[i][j + 1] == 'i' || map[i][j + 1] == 'j')
	{
	  life(pict->win, 1, map, '.');
	  kongleft(map, '.',  pict);
	  put_black(map);
	  kongright(map, '.', pict);
	}
      map[i][j] = str[k + 1];
      str[k + 1] = map[i][j + 1];
      map[i][j + 1] = 'n';
    }
  else
    {
      str[k] = 'l';
      map[i][j] = 'm';
    }
  return (str);
}

char		*move_mob(char *str, char **map, t_pict *pict)
{
  int		i;
  int		j;
  int		k;

  k = 0;
  for (i = 0 ; map[i] ; i++)
    for (j = 0 ; map[i][j] != '\n' ; j = j)
      if (map[i][j] == 'm' || map[i][j] == 'n')
	{
	  if (str[k] == 'l')
	    {
	      str = move_left(str, i, j, k, map, pict);
	      j++;
	    }
	  else
	    {
	      str = move_right(str, i, j, k, map, pict);
	      j = j + 2;
	    }
	  k = k + 2;
	}
      else
	j++;
  return (str);
}

char	*launch_mob(char *mob, char **map, t_pict *pict, unsigned int *t)
{
  if (get_ms() > (*(t) + 500))
    {
      *t = get_ms();
      mob = move_mob(mob, map, pict);
      aff_win(map, pict);
    }
  return (mob);
}
