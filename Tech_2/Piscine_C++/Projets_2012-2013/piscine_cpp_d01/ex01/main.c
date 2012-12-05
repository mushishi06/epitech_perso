/*
** main.c for ex01_d01 in /home/belia-_r/afs/epitech_perso/Tech_2/Piscine_C++/Projets_2012-2013/piscine_cpp_d01/ex01
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Tue Dec  4 22:27:28 2012 belia-_r
** Last update Tue Dec  4 23:29:08 2012 belia-_r
*/

#include <stdlib.h>
#include <stdio.h>

void	menger(double x, double y, double a, double b, int n);

int	main(int ac, char **av)
{
  unsigned long int	n;
  unsigned long int	square_size;

  if (ac < 2)
    {
      printf("Bad Parameters");
      return (EXIT_FAILURE);
    }
  n = strtoul(av[2], NULL, 10);
  square_size = strtoul(av[1], NULL, 10);
  menger(0, 0, (int) square_size, (int) square_size, (int) n);
  return (EXIT_SUCCESS);
}
