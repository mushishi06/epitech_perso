/*
** main.c for 208chevillettes in /home/belia-_r/afs/epitech_perso/Tech_2/Math/208chevillettes
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Wed Jun  5 14:19:22 2013 romain belia-bourgeois
** Last update Sun Jun  9 01:32:37 2013 romain belia-bourgeois
*/

#include	<string.h>
#include	<errno.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<math.h>
#include	"208chevillettes.h"

void	printresult(t_result res[9], double deg_lib)
{
  int	i = 0;
  while (i < deg_lib)
    {
      res[i].val_Tx *= 100;
      i++;
    }
  if (deg_lib == 7){
    printf ("x\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|total\n",
	    res[0].name, res[1].name, res[2].name, res[3].name, res[4].name,
	    res[5].name, res[6].name);
    printf ("________________________________________________________________________\n");
    printf ("Ox\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%d\n",
	    res[0].val_Ox, res[1].val_Ox, res[2].val_Ox, res[3].val_Ox,
	    res[4].val_Ox, res[5].val_Ox, res[6].val_Ox, 100);
    printf ("Tx\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%d\n",
	    res[0].val_Tx, res[1].val_Tx, res[2].val_Tx, res[3].val_Tx,
	    res[4].val_Tx, res[5].val_Tx, res[6].val_Tx, 100);
  }
  if (deg_lib == 8){
    printf ("x\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|total\n",
	    res[0].name, res[1].name, res[2].name, res[3].name, res[4].name,
	    res[5].name, res[6].name, res[7].name);
    printf ("____________________________________________________________________________________\n");
    printf ("Ox\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%d\n",
	    res[0].val_Ox, res[1].val_Ox, res[2].val_Ox, res[3].val_Ox,
	    res[4].val_Ox, res[5].val_Ox, res[6].val_Ox, res[7].val_Ox, 100);
    printf ("Tx\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%d\n",
	    res[0].val_Tx, res[1].val_Tx, res[2].val_Tx, res[3].val_Tx,
	    res[4].val_Tx, res[5].val_Tx, res[6].val_Tx, res[7].val_Tx, 100);
  }
  if (deg_lib == 9){
    printf ("x\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|total\n",
	    res[0].name, res[1].name, res[2].name, res[3].name, res[4].name,
	    res[5].name, res[6].name, res[7].name, res[8].name);
    printf ("___________________________________________________________________________________________________\n");
    printf ("Ox\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%d\n",
	    res[0].val_Ox, res[1].val_Ox, res[2].val_Ox, res[3].val_Ox,
	    res[4].val_Ox, res[5].val_Ox, res[6].val_Ox, res[7].val_Ox,
	    res[8].val_Ox, 100);
    printf ("Tx\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%d\n",
	    res[0].val_Tx, res[1].val_Tx, res[2].val_Tx, res[3].val_Tx,
	    res[4].val_Tx, res[5].val_Tx, res[6].val_Tx, res[7].val_Tx,
	    res[8].val_Tx, 100);
  }
}

bool	verif_number(char *str)
{
  int	i = 0;

  while (str[i] != '\0')
    {
      if (!(str[i] == ',' || str[i] == '.' || (str[i] >= '0' && str[i] <= '9')))
      	return (false);
      if (str[i] == ',')
	str[i] = '.';
      i++;
    }
  return (true);
}

int	verif_val(t_variable *var, t_result res[9])
{
  int	i = 0;

  if(var->o0[0] < EFF_MIN)
    {
      if ((var->o0[0] + var->o1[0]) < EFF_MIN)
	{
	  res[i].val_Ox = (var->o0[0] + var->o1[0] + var->o2[0]);
	  res[i].val_Tx = (var->o0[1] + var->o1[1] + var->o2[1]);
	  res[i].name = strdup("0-2");
	  var->o1[0] = -1;
	  var->o2[0] = -1;
	}
      else
	{
	  res[i].val_Ox = (var->o0[0] + var->o1[0]);
	  res[i].val_Tx = (var->o0[1] + var->o1[1]);
	  res[i].name = strdup("0-1");
	  var->o1[0] = -1;
	}
      i++;
    }
  else
    {
      res[i].val_Ox = (var->o0[0]);
      res[i].val_Tx = (var->o0[1]);
      res[i].name = strdup("0");
      i++;
    }
  if(var->o1[0] != -1 && var->o1[0] < EFF_MIN)
    {
      if ((var->o1[0] + var->o2[0]) < EFF_MIN)
	{
	  res[i].val_Ox = (var->o1[0] + var->o2[0] + var->o3[0]);
	  res[i].val_Tx = (var->o1[1] + var->o2[1] + var->o3[1]);
	  res[i].name = strdup("1-3");
	  var->o2[0] = -1;
	  var->o3[0] = -1;
	}
      else
	{
	  res[i].val_Ox = (var->o1[0] + var->o2[0]);
	  res[i].val_Tx = (var->o1[1] + var->o2[1]);
	  res[i].name = strdup("1-2");
	  var->o2[0] = -1;
	}
      i++;
    }
  else if (var->o1[0] != -1)
    {
      res[i].val_Ox = (var->o1[0]);
      res[i].val_Tx = (var->o1[1]);
      res[i].name = strdup("1");
      i++;
    }
  if(var->o2[0] != -1 && var->o2[0] < EFF_MIN)
    {
      if ((var->o2[0] + var->o3[0]) < EFF_MIN)
	{
	  res[i].val_Ox = (var->o2[0] + var->o3[0] + var->o4[0]);
	  res[i].val_Tx = (var->o2[1] + var->o3[1] + var->o4[1]);
	  res[i].name = strdup("2-4");
	  var->o3[0] = -1;
	  var->o4[0] = -1;
	}
      else
	{
	  res[i].val_Ox = (var->o2[0] + var->o3[0]);
	  res[i].val_Tx = (var->o2[1] + var->o3[1]);
	  res[i].name = strdup("2-3");
	  var->o3[0] = -1;
	}
      i++;
    }
  else if (var->o2[0] != -1)
    {
      res[i].val_Ox = (var->o2[0]);
      res[i].val_Tx = (var->o2[1]);
      res[i].name = strdup("2");
      i++;
    }
  if(var->o3[0] != -1 && var->o3[0] < EFF_MIN)
    {
      if ((var->o3[0] + var->o4[0]) < EFF_MIN)
	{
	  res[i].val_Ox = (var->o3[0] + var->o4[0] + var->o5[0]);
	  res[i].val_Tx = (var->o3[1] + var->o4[1] + var->o5[1]);
	  res[i].name = strdup("3-5");
	  var->o4[0] = -1;
	  var->o5[0] = -1;
	}
      else
	{
	  res[i].val_Ox = (var->o3[0] + var->o4[0]);
	  res[i].val_Tx = (var->o3[1] + var->o4[1]);
	  res[i].name = strdup("3-4");
	  var->o4[0] = -1;
	}
      i++;
    }
  else if (var->o3[0] != -1)
    {
      res[i].val_Ox = (var->o3[0]);
      res[i].val_Tx = (var->o3[1]);
      res[i].name = strdup("3");
      i++;
    }
  if(var->o4[0] != -1 && var->o4[0] < EFF_MIN)
    {
      if ((var->o4[0] + var->o5[0]) < EFF_MIN)
	{
	  res[i].val_Ox = (var->o4[0] + var->o5[0] + var->o6[0]);
	  res[i].val_Tx = (var->o4[1] + var->o5[1] + var->o6[1]);
	  res[i].name = strdup("4-6");
	  var->o5[0] = -1;
	  var->o6[0] = -1;
	}
      else
	{
	  res[i].val_Ox = (var->o4[0] + var->o5[0]);
	  res[i].val_Tx = (var->o4[1] + var->o5[1]);
	  res[i].name = strdup("4-5");
	  var->o5[0] = -1;
	}
      i++;
    }
  else if (var->o4[0] != -1)
    {
      res[i].val_Ox = (var->o4[0]);
      res[i].val_Tx = (var->o4[1]);
      res[i].name = strdup("4");
      i++;
    }
  if(var->o5[0] != -1 && var->o5[0] < EFF_MIN)
    {
      if ((var->o5[0] + var->o6[0]) < EFF_MIN)
	{
	  res[i].val_Ox = (var->o5[0] + var->o6[0] + var->o7[0]);
	  res[i].val_Tx = (var->o5[1] + var->o6[1] + var->o7[1]);
	  res[i].name = strdup("5-7");
	  var->o6[0] = -1;
	  var->o7[0] = -1;
	}
      else
	{
	  res[i].val_Ox = (var->o5[0] + var->o6[0]);
	  res[i].val_Tx = (var->o5[1] + var->o6[1]);
	  res[i].name = strdup("5-6");
	  var->o6[0] = -1;
	}
      i++;
    }
  else if (var->o5[0] != -1)
    {
      res[i].val_Ox = (var->o5[0]);
      res[i].val_Tx = (var->o5[1]);
      res[i].name = strdup("5");
      i++;
    }
  if(var->o6[0] != -1 && var->o6[0] < EFF_MIN)
    {
      if ((var->o6[0] + var->o7[0]) < EFF_MIN)
	{
	  res[i].val_Ox = (var->o6[0] + var->o7[0] + var->o8[0]);
	  res[i].val_Tx = (var->o6[1] + var->o7[1] + var->o8[1]);
	  res[i].name = strdup("6+");
	  var->o7[0] = -1;
	  var->o8[0] = -1;
	}
      else
	{
	  res[i].val_Ox = (var->o6[0] + var->o7[0]);
	  res[i].val_Tx = (var->o6[1] + var->o7[1]);
	  res[i].name = strdup("6-7");
	  var->o7[0] = -1;
	}
      i++;
    }
  else if (var->o6[0] != -1)
    {
      res[i].val_Ox = (var->o6[0]);
      res[i].val_Tx = (var->o6[1]);
      res[i].name = strdup("6");
      i++;
    }
  if(var->o7[0] != -1 && (var->o7[0] < EFF_MIN || var->o8[0] < EFF_MIN))
    {
      if ((var->o7[0] + var->o8[0]))
	{
	  res[i].val_Ox = (var->o7[0] + var->o8[0]);
	  res[i].val_Tx = (var->o7[1] + var->o8[1]);
	  res[i].name = strdup("7+");
	  var->o8[0] = -1;
	}
      i++;
    }
  else if (var->o7[0] != -1)
    {
      res[i].val_Ox = (var->o7[0]);
      res[i].val_Tx = (var->o7[1]);
      res[i].name = strdup("7");
      i++;
      res[i].val_Ox = (var->o8[0]);
      res[i].val_Tx = (var->o8[1]);
      res[i].name = strdup("8");
      i++;
    }
  //  printf ("i = [%d]\n",i);
  return (i);
}

void	calc_p(t_variable *var)
{
  var->p = (((0 * var->o0[0]) + (1 * var->o1[0]) + (2 * var->o2[0]) +
	     (3 * var->o3[0]) + (4 * var->o4[0]) + (5 * var->o5[0]) +
	     (6 * var->o6[0]) + (7 * var->o7[0]) +(8 * var->o8[0])) / 10000);
}

double	calc_x2(t_result res[9], double deg_lib)
{
  double	sommeCarre = 0;
  int		i = 0;

  while (i < deg_lib)
    {
      sommeCarre += (pow((res[i].val_Ox - res[i].val_Tx), 2) / res[i].val_Tx);
      i++;
    }
  return (sommeCarre);
}

void	run(t_variable *_var)
{
  bool		_end = false;
  t_result	res[9];
  double	sommeCarre = 0, max, min;
  int		deg_lib = 0, i = 0;

  calc_p(_var);
  loi_binomial(_var->p, _var);
  deg_lib = verif_val(_var, res);
  printresult(res, deg_lib);
  sommeCarre = calc_x2(res, deg_lib);
  printf ("\nloi choisie :\t\t\tB(100, %.4f)\n",_var->p);
  printf ("somme des carrés des écarts :\tX2 = %.3f\n", sommeCarre);
  printf ("degrés de liberté :\t\tv = %d\n", (deg_lib - 2));
  while (i < 14 && !(_end))
    {
      if (sommeCarre > donnees[deg_lib - 2].nb[i])
	i++;
      else
	{
	  _end = true;
	  max = donnees[0].nb[i - 1];
	  min = donnees[0].nb[i];
	}
    }
  printf ("validité de l’ajustement :\t%.0f%% < P < %.0f%%\n", max, min);
}

int	init_variable(t_variable *var, char *argv[])
{
  var->o0[0] = atof(argv[1]);
  var->o1[0] = atof(argv[2]);
  var->o2[0] = atof(argv[3]);
  var->o3[0] = atof(argv[4]);
  var->o4[0] = atof(argv[5]);
  var->o5[0] = atof(argv[6]);
  var->o6[0] = atof(argv[7]);
  var->o7[0] = atof(argv[8]);
  var->o8[0] = atof(argv[9]);
  if (var->o0[0] < 0 || var->o1[0] < 0 || var->o2[0] < 0 || var->o3[0] < 0 ||
      var->o4[0] < 0 || var->o5[0] < 0 || var->o6[0] < 0 || var->o7[0] < 0 ||
      var->o8[0] < 0)
    {
      fprintf(stderr, USAGE_NEG);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
  t_variable	variable;

  if (argc != 10)
    {
      fprintf(stderr, USAGE);
      return (EXIT_FAILURE);
    }
  if (init_variable(&variable, argv) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  run(&variable);
  return EXIT_SUCCESS;
}
