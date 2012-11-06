/*
** checkEvents.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r/etape_2
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sat Mar  3 20:16:49 2012 belia-_r
** Last update Sun Mar  4 19:36:43 2012 belia-_r
*/

#include	"epikong.h"

char	checkEvents(t_Input* in, t_pict *pict, char **map, char c)
{
  SDL_Delay(20);
  if (JUMPRIGHT(in->key))
    return (kongjumpright(map, c, pict));
  else if (JUMPLEFT(in->key))
    return (kongjumpleft(map, c, pict));
  else if (UP(in->key))
    return (kongup(map, c, pict));
  else if (DOWN(in->key))
    return (kongdown(map, c, pict));
  else if (RIGHT(in->key))
    {
      SDL_Delay(20);
      return (kongright(map, c, pict));
    }
  else if (LEFT(in->key))
    {
      SDL_Delay(20);
      return (kongleft(map, c, pict));
    }
  else if (JUMP(in->key))
    return (kongjump(map, c, pict));
}
