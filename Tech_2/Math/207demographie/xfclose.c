/*
** xfclose.c for 207demographie in /home/belia-_r/afs/epitech_perso/Tech_2/Math/207demographie
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Sat Jun  1 18:41:12 2013 romain belia-bourgeois
** Last update Sat Jun  1 18:41:31 2013 romain belia-bourgeois
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<unistd.h>

int		xfclose(FILE *fp)
{
  if (fclose(fp) == -1)
    {
      perror("fclose");
      exit(EXIT_FAILURE);
    }
  return (0);
}
