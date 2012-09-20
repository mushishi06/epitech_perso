/*
** open_path.c for 206 in /home/belia-_r/afs/Math/206
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Wed Apr 25 16:24:10 2012 belia-_r
** Last update Sun Apr 29 12:15:01 2012 belia-_r
*/

#define		_GNU_SOURCE
#include	<stdio.h>
#include	<stdlib.h>
#include	"206.h"
int		parse_line(const char *str)
{
  int		i = 0;

  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] != ' ' && str[i] != '\t')
    i++;
  return (i);
}

int		open_path(char *path, float **tab)
{
  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  int	nb_params;
  int	i;

  i = 0;
  fp = fopen(path, "r");
  if (fp == NULL)
    exit(EXIT_FAILURE);
  if ((read = getline(&line, &len, fp)) == -1)
    {
      perror("fichier vide");
      exit(EXIT_FAILURE);
    }
  nb_params = atoi(line);
  if (nb_params > 0)
    {
      tab[0] = xmalloc((nb_params + 1) *sizeof(float));
      tab[1] = xmalloc((nb_params + 1) *sizeof(float));
      while ((i < nb_params) && ((read = getline(&line, &len, fp)) != -1))
	{
	  tab[0][i] = atof(line);
	  tab[1][i] = atof(&line[parse_line(line)]);
	  /* aff*/
	  printf("[%f] [%f] \n", tab[0][i], tab[1][i]);
	  i++;
	}
    }
  if (line)
    free(line);
  xfclose(fp);
  return (nb_params);
}
