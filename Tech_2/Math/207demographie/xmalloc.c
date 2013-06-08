/*
** xmalloc.c for 207demographie in /home/belia-_r/afs/epitech_perso/Tech_2/Math/207demographie
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Sat Jun  1 18:42:59 2013 romain belia-bourgeois
** Last update Sat Jun  1 20:01:48 2013 romain belia-bourgeois
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>

void*			xmalloc(size_t size)
{
  void*			ptr;

  if (!(ptr = malloc(size)))
    {
      perror("malloc");
      exit(EXIT_FAILURE);
    }
  memset(ptr, '\0', size);
  return (ptr);
}
