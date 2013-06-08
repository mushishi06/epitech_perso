/*
** main.c for 206neutrinos in /home/belia-_r/afs/epitech_perso/Tech_2/Math/206neutrinos
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Thu May 16 17:54:40 2013 romain belia-bourgeois
** Last update Sat May 18 00:11:03 2013 romain belia-bourgeois
*/

#include	<string.h>
#include	<errno.h>
#include        <string>
#include        <sstream>
#include        <iostream>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<math.h>
#include	"206neutrinos.h"

void	printresult(t_result *_res)
{
  printf ("\tantal mãlinder :\t%2.f\n\tstandardafvilgelse :\t%2.2f\n\taritmetisk gennemsnit :\t%2.2f\n\tkvadratisk gennemsnit :\t%2.2f\n\tharmonisk  gennemsnit :\t%2.2f\n\n",
	  _res->newNbMesures, _res->newEcTy, _res->newMoyArith,
	  _res->newMoyQuadra, _res->newMoyHarmo);
}

void	init_struct(t_variable *_var, t_result *_res, double nbMesures, double moyArith, double moyHarmo, double ecTy)
{
  _var->nbMesures = nbMesures;
  _var->moyArith = moyArith;
  _var->moyHarmo = moyHarmo;
  _var->ecTy = ecTy;
  _var->somme = (moyArith * nbMesures);
  _var->sommeCarre = ((pow(ecTy, 2) + pow(moyArith, 2)) * nbMesures);
  _res->newNbMesures = (nbMesures + 1);
  _res->newMoyArith = 0;
  _res->newMoyQuadra = 0;
  _res->newMoyHarmo = 0;
  _res->newEcTy = 0;
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

void	run(double nbMesures, double moyArith, double moyHarmo, double ecTy)
{
  bool		_end = false;
  t_variable	_var;
  t_result	_res;
  double	nbAdd = 0;
  int		n;
  char		p[SIZE_BUFFER];

  memset(p, '\0', SIZE_BUFFER);
  init_struct(&_var, &_res, nbMesures, moyArith, moyHarmo, ecTy);
  while (!_end)
    {
      nbAdd = write(1, "indtast din vaerdi : ", 21);
      n = read(0, p, SIZE_BUFFER - 1);
      p[n - 1] = '\0';
      if (n > 1 && n < SIZE_BUFFER)
	{
	  if (strncmp("ende", p, n) == 0)
	    _end = true;
	  else if (verif_number(p))
	    {
	      nbAdd = atof(p);
	      moy_arith(&_var, &_res, nbAdd);
	      moy_quadra(&_var, &_res, nbAdd);
	      moy_harmo(&_var, &_res, nbAdd);
	      ec_type(&_var, &_res, nbAdd);
	      printresult(&_res);
	      usleep(500);
	    }
	}
      memset(p, '\0', SIZE_BUFFER);
      init_struct(&_var, &_res, _res.newNbMesures, _res.newMoyArith,
		  _res.newMoyHarmo, _res.newEcTy);
    }
}

int	main(int argc, char *argv[])
{
  double	nbMesures, moyArith, moyHarmo, ecTy;

  if (argc != 5)
    {
      fprintf(stderr, "Bad parameters : verif number of parameters\nPlease use \"./206neutrinos [nb1] [nb2] [nc3] [nb4]\"\n");
      return (EXIT_FAILURE);
    }
  nbMesures = atof(argv[1]);
  moyArith = atof(argv[2]);
  moyHarmo = atof(argv[3]);
  ecTy = atof(argv[4]);
  if (nbMesures < 1 || moyArith< 0 || moyHarmo< 0 || ecTy< 0)
    {
      fprintf(stderr, "Bad parameters : no NEGATIF paramater\nPlease use \"./206neutrinos [nb1] [nb2] [nc3] [nb4]\"\n");
      return (EXIT_FAILURE);
    }
  run(nbMesures, moyArith, moyHarmo, ecTy);
  return EXIT_SUCCESS;
}
