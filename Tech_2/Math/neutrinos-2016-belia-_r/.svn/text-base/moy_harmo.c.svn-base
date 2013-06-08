/*
** moy_harmo.c for 206neutrinos in /home/belia-_r/afs/epitech_perso/Tech_2/Math/206neutrinos
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Thu May 16 18:48:27 2013 romain belia-bourgeois
** Last update Fri May 17 00:18:24 2013 romain belia-bourgeois
*/

#include	<math.h>
#include	"206neutrinos.h"

double	moy_harmo(t_variable *_var, t_result *_res, double nbAdd)
{
  _res->newMoyHarmo = (_res->newNbMesures /
		       ((1 / nbAdd) + (_var->nbMesures / _var->moyHarmo)));
  return (_res->newMoyHarmo);
}
