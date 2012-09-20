/*
** main.c for 206 in /home/belia-_r/afs/Math/206
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Wed Apr 25 16:11:00 2012 belia-_r
** Last update Sun Apr 29 12:08:33 2012 belia-_r
*/

#include	<stdlib.h>
#include	"206.h"

void		run(char *path)
{
  float		**tab;
  int		nb_params;

  tab  = xmalloc(3 * sizeof(*tab));
  tab[2] = NULL;
  nb_params = open_path(path, tab);
  /*aff*/
  printf("nb_params = [%d] :\n", nb_params);
}

int	main(int ac, char **av)
{
  if (ac >= 2)
    run(av[1]);
  return (EXIT_SUCCESS);
}
