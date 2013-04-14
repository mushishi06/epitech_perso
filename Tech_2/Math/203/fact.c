/*
** fact.c for 203hotline in /home/belia-_r/afs/epitech_perso/Tech_2/Math/203
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Thu Mar 21 23:47:54 2013 romain belia-bourgeois
** Last update Fri Mar 22 00:04:43 2013 romain belia-bourgeois
*/

#include	<stdio.h>

double		fact(double n)
{
  double	f = 1;

  while (n > 1)
    f *= n--;
  printf ("factoriel de [%f] = [%f]\n",n, f);
  return (f);
}

double		combinaison(int n, int k)
{
  double	res = 0;

  res = ((fact(n)) / (fact(k) * fact(n - k)));
  return (res);
}
