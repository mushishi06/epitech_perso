/*
** main.c for 209sondage in /home/belia-_r/afs/epitech_perso/Tech_2/Math/209sondage
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Sun Jun 16 00:43:52 2013 romain belia-bourgeois
** Last update Sun Jun 16 11:34:02 2013 romain belia-bourgeois
*/

#include	<string.h>
#include	<errno.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<math.h>
#include	"209sondage.h"

void	printresult(t_variable *var, double intc95, double intc99, double variance)
{
  double	a, a1, b, b1;

  a = (var->p_vote - intc95);
  if (a < 0)
    a = 0;
  a1 = (var->p_vote + intc95);
  if (a1 > 100.0)
    a1 = 100;
  b = (var->p_vote - intc99);
  if (b < 0)
    b = 0;
  b1 = (var->p_vote + intc99);
  if (b1 > 100.0)
    b1 = 100;
  printf ("taille de la population :\t%d\n", var->size_pop);
  printf ("taille de l'echantillon :\t%d\n", var->size_ech);
  printf ("resultat du sondage :\t\t%0.2f%%\n", var->p_vote);
  printf ("variance estimee :\t\t%f\n", variance);
  printf ("intervalle de confiance a 95%% :\t[%0.2f%% ; %0.2f%%]\n", a, a1);
  printf ("intervalle de confiance a 99%% :\t[%0.2f%% ; %0.2f%%]\n", b, b1);
}

double	calc_intc95(double variance)
{
  return (((2 * 1.96) * sqrt(variance)) / 2 * 100);
}

double	calc_intc99(double variance)
{
  return (((2 * 2.58) * sqrt(variance)) / 2 * 100);
}

double	calc_variance(t_variable *data)
{
  double	var_b = 0, p = 0, pop, ech;
  double	res = 0;

  pop = data->size_pop;
  ech = data->size_ech;

  p = data->p_vote / 100;
  var_b = (p * (1 - p));

  res = ((var_b / ech) * ((pop - ech) / (pop - 1)));
  return (res);
}

void	run(t_variable *data)
{
  double	intc95 = 0, intc99 = 0, var = 0.000464;

  var = calc_variance(data);
  intc95 = calc_intc95(var);
  intc99 = calc_intc99(var);
  printresult(data, intc95, intc99, var); /* variance */
}

int	init_variable(t_variable *var, char *argv[])
{
  var->size_pop = atoi(argv[1]);
  var->size_ech = atoi(argv[2]);
  var->p_vote = atof(argv[3]);
  if (var->size_pop < 0 || var->size_ech < 0 || var->p_vote < 0)
    {
      fprintf(stderr, USAGE_NEG);
      return (EXIT_FAILURE);
    }
  if (var->size_pop < var->size_ech)
    {
      fprintf(stderr, "Error size_pop need > size_ech\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
  t_variable	variable;

  if (argc != 4)
    {
      fprintf(stderr, USAGE);
      return (EXIT_FAILURE);
    }
  if (init_variable(&variable, argv) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  run(&variable);
  return EXIT_SUCCESS;
}
