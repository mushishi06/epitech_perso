/*
** gauss.c for 205qi in /home/belia-_r/afs/epitech_perso/Tech_2/Math/205
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Thu May  2 22:26:25 2013 romain belia-bourgeois
** Last update Thu May  2 22:43:27 2013 romain belia-bourgeois
*/

#include	<math.h>

double	gauss(double ect, double u, double i)
{
  return ((1.f / (ect * sqrt(2.f * M_PI))) *
	  exp(-(pow((i - u), 2.f) / (2 * pow(ect, 2.f)))));
}
