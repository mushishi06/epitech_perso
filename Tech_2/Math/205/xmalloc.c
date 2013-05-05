/*
** xmalloc.c for 205Qi in /home/belia-_r/afs/epitech_perso/Tech_2/Math/205
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Sun May  5 12:51:29 2013 romain belia-bourgeois
** Last update Sun May  5 12:51:30 2013 romain belia-bourgeois
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
