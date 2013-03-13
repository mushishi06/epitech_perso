/*
** xmalloc.c for 202invendus in /home/belia-_r/afs/epitech_perso/Tech_2/Math/202
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Mar 10 21:23:24 2013 romain belia-bourgeois
** Last update Sun Mar 10 21:29:25 2013 romain belia-bourgeois
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
