/*
** menger.c for ex01_d01 in /home/belia-_r/afs/epitech_perso/Tech_2/Piscine_C++/Projets_2012-2013/piscine_cpp_d01/ex01
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Tue Dec  4 23:25:01 2012 belia-_r
** Last update Tue Dec  4 23:25:03 2012 belia-_r
*/

#include <stdlib.h>
#include <stdio.h>

void	menger(double x, double y, double a, double b, int n)
{
  int	size;

  if (n > 0)
    {
      size = (int) ((x + 2 * a / 3) - (x + a / 3));
      printf ("%.3d %.3d %.3d\n", size, (int) (y + b / 3), (int) (x + a / 3));
      menger(x, y, a / 3, b / 3, n - 1);
      menger(x + a / 3, y, a / 3, b / 3, n - 1);
      menger(x + 2 * a / 3, y, a / 3, b / 3, n - 1);
      menger(x, y + b / 3, a / 3, b / 3, n - 1);
      menger(x + 2 * a / 3, y + b / 3, a / 3, b / 3, n - 1);
      menger(x, y + 2 * b / 3, a / 3, b / 3, n - 1);
      menger(x + a / 3, y + 2 * b / 3, a / 3, b / 3, n - 1);
      menger(x + 2 * a / 3, y + 2 * b / 3, a / 3, b / 3, n - 1);
    }
}
