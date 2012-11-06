/*
** others.c for epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r/etape_2
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Mar  4 16:10:41 2012 belia-_r
** Last update Sun Mar  4 22:06:14 2012 belia-_r
*/

#include "epikong.h"

unsigned int		get_ms()
{
  struct timeval	time;

  gettimeofday(&time, NULL);
  return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
