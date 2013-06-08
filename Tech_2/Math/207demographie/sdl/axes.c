/*
** axes.c for 205Qi in /home/belia-_r/afs/epitech_perso/Tech_2/Math/205
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Sun May  5 12:51:43 2013 romain belia-bourgeois
** Last update Sun Jun  2 23:32:22 2013 romain belia-bourgeois
*/

#include	<SDL/SDL_gfxPrimitives.h>
#include	"sdl_math.h"

void		draw_lgd_x(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_x)
{
  int		a, b, af;
  SDL_Rect	position;
  char	buff[4];

  memset(buff, '\0', 4);
  for ((af = 0, a = 50); a < WIN_WIDTH; (a += (50 * OFFSET_W), af += 50))
    {
      position.x = a;
      for (b = pos_x - 6; b < pos_x; b++)
	{
	  position.y = b;
	  SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
	  SDL_BlitSurface(rectangle, NULL, ecran, &position);
	}
      sprintf(buff, "%d", af);
      stringColor(ecran, a - 5, (WIN_HEIGHT - 45), buff, 0xffffffff);
      memset(buff, '\0', 4);
    }
  a -= (50 *OFFSET_W);
  draw_axe_y(ecran, rectangle, a);
  draw_lgd_y(ecran, rectangle, a, a + 25);
  draw_fleche_y(ecran, rectangle, a);
  SDL_Flip(ecran);
}

void		draw_axe_x(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_x)
{
  int		a;
  SDL_Rect	position;

  for (a = 50; a < WIN_WIDTH; a++)
    {
      position.x = a;
      position.y = pos_x;
      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
      SDL_BlitSurface(rectangle, NULL, ecran, &position);
    }
  SDL_Flip(ecran);
}

void		draw_lgd(SDL_Surface *ecran)
{
  char	buff[12];
  int	i;

  memset(buff, '\0', 12);
  sprintf(buff, "Probabilite");
  for (i = 0; i < 11; i++)
    {
      characterColor(ecran, 8, (220 + (i * 20)), buff[i], 0xffffffff);
    }
  i += 4;
  stringColor(ecran, 4, (210 + (i * 15)), "(%)", 0xffffffff);
}

void		draw_lgd_y(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_y, int py)
{
  int		a, b, af;
  SDL_Rect	position;
  char		buff[4];

  memset(buff, '\0', 4);
  for ((af = 100, a = (50)); a < WIN_WIDTH; (a += (20 * OFFSET_H), af -= 20))
    {
      position.y = a;
      for (b = pos_y ; b < pos_y + 6; b++)
	{
	  position.x = b;
	  SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
	  SDL_BlitSurface(rectangle, NULL, ecran, &position);
	}
      sprintf(buff, "%d", af);
      stringColor(ecran, (py), a - 3, buff, 0xffffffff);
      memset(buff, '\0', 4);
    }
  SDL_Flip(ecran);
}
void		draw_axe_y(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_y)
{
  int		a;
  SDL_Rect	position;

  for (a = 0; a < WIN_HEIGHT - 50; a++)
    {
      position.x = pos_y;
      position.y = a;
      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
      SDL_BlitSurface(rectangle, NULL, ecran, &position);
    }
  SDL_Flip(ecran);
}
