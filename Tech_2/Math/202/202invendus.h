/*
** 202invendus.h for 202invendus in /home/belia-_r/afs/epitech_perso/Tech_2/Math/202
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Mon Mar  4 22:55:27 2013 romain belia-bourgeois
** Last update Wed Mar 13 19:05:14 2013 romain belia-bourgeois
*/

#ifndef __202INVENDUS_H_
# define __202INVENDUS_H_

#include	<stdbool.h>
#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>
#define USAGE "Usage : ./202invendus [a] [b]\nAvec a et b deux entiers supérieurs à 50\n"

bool	check_params(char *str);
bool	get_params(char **av, int *a, int *b);
void	print_results(double **tab,double **zab);
void	*xmalloc(size_t size);
void	calc_loi_conj(double **tab, double **print, int a, int b);
void	loi_marginale_X(double **tab, double **print);
void	loi_marginale_Y(double **tab, double **print);
void	total_marginale(double **tab, double **print);
void	proba_z(double **tab, double **zab);
void	exit_error();
double	darrondi(double fvaleur);

double		esp_x(double **tab);
double		var_x(double **tab);
double		esp_y(double **tab);
double		var_y(double **tab);
double		esp_z(double **tab);
double		var_z(double **tab);

#endif  /* __202INVENDUS_H_ */
