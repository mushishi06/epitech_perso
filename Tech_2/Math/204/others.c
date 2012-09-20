/*
** others.c for 204 in /home/belia-_r/afs/Math/204
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Apr 22 20:45:37 2012 belia-_r
** Last update Sun Apr 22 20:45:39 2012 belia-_r
*/

#include <math.h>

double		inter1(double i)
{
  return ((i >= 2.f && i <= 5.f) ? (1.f/3.f) : 0.f);
}

double		inter2(double i)
{
  return ((i >= -1.0 && i <= 1.0) ? (1.f - fabs(i)) : 0.f);
}

double	        expo(double i)
{
  return ((i > 0.f) ? exp(-i) : 0.f);
}

double		gauss(double i)
{
  return ((1.f/sqrt(2.f * M_PI)) * exp(-(i * i) / 2.f));
}

double		gauss2(double i)
{
  return ((1.f/(2 * sqrt(2.f * M_PI))) * exp(-((i - 3) * (i - 3)) / 8.f));
}
