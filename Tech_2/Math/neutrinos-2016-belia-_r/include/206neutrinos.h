/*
** 206neutrinos.h for 206neutrinos in /home/belia-_r/afs/epitech_perso/Tech_2/Math/206neutrinos
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Thu May 16 17:53:15 2013 romain belia-bourgeois
** Last update Sat May 18 00:02:59 2013 romain belia-bourgeois
*/

#ifndef __206NEUTRINOS_H_
# define __206NEUTRINOS_H_

#define	SIZE_BUFFER	512

typedef struct s_variable
{
  double	nbMesures;
  double	moyArith;
  double	moyHarmo;
  double	somme;
  double	sommeCarre;
  double	ecTy;
}	t_variable;

typedef struct s_result
{
  double	newNbMesures;
  double	newMoyArith;
  double	newMoyQuadra;
  double	newMoyHarmo;
  double	newEcTy;
}	t_result;


double	moy_arith(t_variable *_var, t_result *_res, double nbAdd);
double	moy_quadra(t_variable *_var, t_result *_res, double nbAdd);
double	moy_harmo(t_variable *_var, t_result *_res, double nbAdd);
double	ec_type(t_variable *_var, t_result *_res, double nbAdd);

#endif /* __206NEUTRINOS_H_ */
