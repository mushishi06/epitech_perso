/*
** 203hotline.h for 203hotline in /home/belia-_r/afs/epitech_perso/Tech_2/Math/203
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Wed Mar 20 21:50:28 2013 romain belia-bourgeois
** Last update Thu Mar 21 23:58:55 2013 romain belia-bourgeois
*/

#ifndef __203HOTLINE_H_
# define __203HOTLINE_H_

#include		<stdbool.h>
#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>

#define USAGE "Usage : ./202invendus [a] [b]\nAvec a et b deux entiers supérieurs à 50\n"

bool	check_params(char *str);
bool	get_params(char **av, int *a, int *b, int para);
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

double		fact(double n);
double		combinaison(int n, int k);

#endif  /* __203HOTLINE_H_ */
