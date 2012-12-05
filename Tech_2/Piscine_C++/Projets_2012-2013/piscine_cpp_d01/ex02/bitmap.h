/*
** bitmap.h for ex02d01 in /home/belia-_r/afs/epitech_perso/Tech_2/Piscine_C++/Projets_2012-2013/piscine_cpp_d01/ex02
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Tue Dec  4 23:53:45 2012 belia-_r
** Last update Wed Dec  5 00:05:33 2012 belia-_r
*/

#ifndef __BITMAP_H__
# DEFINE __BITMAP_H__

#include	<stdint.h>

typedef struct	s_bmp_header
{
  magic;
  size;
  _app1;
  _app2;
  offset;
}	t_bmp_header;

typedef struct	s_bmp_info_header
{
  size;
  width;
  height;
  planes;
  bpp;
  compression;
  raw_data_size;
  h_resolution;
  v_resolution;
  palette_size;
  important_colors;
}	t_bmp_info_header;

void	make_bmp_header(t_bmp_header *header, size_t size);
void	make_bmp_info_header(t_bmp_info_header *header, size_t size);

#endif /* __BITMAP_H__ */
