/*
** xmalloc.c for 206 in /home/belia-_r/afs/Math/206
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Wed Apr 25 16:22:37 2012 belia-_r
** Last update Sun Apr 29 11:32:03 2012 belia-_r
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
