/*
** ec_type.c for 206neutrinos in /home/belia-_r/afs/epitech_perso/Tech_2/Math/206neutrinos
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Thu May 16 18:47:34 2013 romain belia-bourgeois
** Last update Sat May 18 00:05:17 2013 romain belia-bourgeois
*/

#include	<math.h>
#include	"206neutrinos.h"

double		var(t_variable *_var, t_result *_res, double nbAdd)
{
  double	tmp;

  tmp = ((_var->sommeCarre + pow(nbAdd, 2)) / _res->newNbMesures);
  return (tmp - pow(_res->newMoyArith, 2));
}

double		ec_type(t_variable *_var, t_result *_res, double nbAdd)
{
  _res->newEcTy = sqrt(var(_var, _res, nbAdd));
  return (_res->newEcTy);
}
