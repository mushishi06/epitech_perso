/*
** parseur.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sat Mar  3 13:14:00 2012 belia-_r
** Last update Mon Mar  5 17:18:11 2012 belia-_r
*/

#include "epikong.h"

int		check_length(char **wtab)
{
  int		i;
  int		length;

  length = strlen(wtab[0]);
  for (i = 0; wtab[i] != NULL; i++)
    {
      if (length != (int)strlen(wtab[i]))
	{
	  printf("Map : Longueur des lignes inconstante\n");
	}
    }
  return (length);
}

FILE		*open_map(char *str)
{
  FILE		*fd;

  fd = fopen(str, "r");
  if (fd == NULL)
    {
      printf("%s, no such file or directory\n", str);
      return (NULL);
    }
  return (fd);
}

char		**parse(char *str, int *length, int *height)
{
  FILE		*fd;
  char		*line = NULL;
  char		**wtab;
  int		i = 0;
  size_t	len;
  ssize_t	read;

  (*height) = 0;
  if ((wtab = malloc(sizeof(char **) * 512)) == NULL)
    return (NULL);
  if ((fd = open_map(str)) == NULL)
    return (NULL);
  for (i = 0; (read = getline(&line, &len, fd)) != -1; i++)
    {
      wtab[i] = malloc(sizeof(char *) * read);
      if (wtab[i] == NULL)
	return (NULL);
      strcpy(wtab[i], line);
      (*height)++;
    }
  wtab[i] = NULL;
  if (line)
    free(line);
  (*length) = check_length(wtab);
  return (wtab);
}
