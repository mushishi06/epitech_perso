/*
** 209sondage.h for 209sondage in /home/belia-_r/afs/epitech_perso/Tech_2/Math/209sondage
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Jun 16 02:28:42 2013 romain belia-bourgeois
** Last update Sun Jun 16 02:45:43 2013 romain belia-bourgeois
*/

#ifndef __209SONDAGE_H_
# define __209SONDAGE_H_

#include        <string>
#include        <sstream>
#include        <iostream>

#define USAGE "Bad parameters : verif number of parameters\nPlease use \"./209sondage [size_pop] [size_ech] [%% vote]\"\n"

#define USAGE_NEG "Bad parameters : no NEGATIF paramater\nPlease use \"./209sondage [size_pop] [size_ech] [%% vote]\"\n"

typedef struct s_variable
{
  int		size_pop;
  int		size_ech;
  double	p_vote;
}	t_variable;

double		loi_binomial(double n, double p);

#endif /* __209SONDAGE_H_ */
