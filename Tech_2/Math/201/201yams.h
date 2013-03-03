/*
** 201yams.h for 201yams in /home/belia-_r/afs/epitech_perso/Tech_2/Math/201
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Sat Mar  2 00:19:59 2013 romain belia-bourgeois
** Last update Sun Mar  3 18:19:53 2013 romain belia-bourgeois
*/

#ifndef __201YAMS_H_
# define __201YAMS_H_

#include	<stdbool.h>
#define USAGE "Bad parameter!!!\nUsage : ./201yams des_1 des_2 des_3 des_4 des_5 coninaison.\n"

typedef struct	s_lancer
{
  int	des[5];
  char	*comb;
}		t_lancer;

typedef struct	s_comb
{
  char	*str;
  int	t;
  float	(*fonc)();
}		t_comb;

bool	check_des(int des);
int	get_one_param(char *str, int size);
int	check_lancer(int *lancer, int dc);

float	paire(t_lancer *lancer);
float	brelan(t_lancer *lancer);
float	carre(t_lancer *lancer);
float	full(t_lancer *lancer);
float	suite(t_lancer *lancer);
float	yams(t_lancer *lancer);

#endif /* __201YAMS_H_ */
