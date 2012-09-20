/*
** xopen.c for mysh in /home/belia-_r/works/psu/minishell1
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Tue Nov  8 14:53:57 2011 romain belia-bourgeois
** Last update Wed Apr 25 19:32:35 2012 belia-_r
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	xopen(char *pathname, int flag)
{
  int	fd;

  if ((fd = open(pathname, flag)) == -1)
    {
      perror("Error open");
      exit(EXIT_FAILURE);
    }
  return (fd);
}
