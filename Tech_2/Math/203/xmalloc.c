/*
** xmalloc.c for 203hotline in /home/belia-_r/afs/epitech_perso/Tech_2/Math/203
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Wed Mar 20 21:47:40 2013 romain belia-bourgeois
** Last update Wed Mar 20 21:47:41 2013 romain belia-bourgeois
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
