/*
** xfclose.c for 206 in /home/belia-_r/afs/Math/206
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Wed Apr 25 16:23:14 2012 belia-_r
** Last update Sun Apr 29 12:15:35 2012 belia-_r
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<unistd.h>

int			xfclose(FILE *fp)
{
  if (fclose(fp) == -1)
    {
      perror("fclose");
      exit(EXIT_FAILURE);
    }
  return (0);
}
