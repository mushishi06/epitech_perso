/*
** moy_quadra.c for 206neutrinos in /home/belia-_r/afs/epitech_perso/Tech_2/Math/206neutrinos
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Thu May 16 18:48:01 2013 romain belia-bourgeois
** Last update Fri May 17 23:53:52 2013 romain belia-bourgeois
*/

#include	<math.h>
#include	"206neutrinos.h"

double	moy_quadra(t_variable *_var, t_result *_res, double nbAdd)
{
  double	tmp;
  double	tmp2;

  tmp = (_var->sommeCarre + pow(nbAdd, 2));
  tmp2 = (tmp / _res->newNbMesures);
  _res->newMoyQuadra = sqrt(tmp2);
  return (_res->newMoyQuadra);
}
