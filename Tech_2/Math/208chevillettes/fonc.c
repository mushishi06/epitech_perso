/*
** fonc.c for 208chevillettes in /home/belia-_r/afs/epitech_perso/Tech_2/Math/208chevillettes
**
** Made by romain belia-bourgeois
** Login   <belia-_r@epitech.net>
**
** Started on  Sat Jun  8 20:13:20 2013 romain belia-bourgeois
** Last update Sun Jun  9 01:08:58 2013 romain belia-bourgeois
*/

#include	<math.h>
#include	<gmpxx.h>
#include	"208chevillettes.h"

double		min(double a, double b)
{
  return ((a <= b) ? a : b);
}

mpz_class	 coeff_binomial(double n, double k)
{
  mpz_t b, tmp, tmp2, tmp3, i, k_, n_;
  double k2, i2 = 0;

  mpz_init_set_d(b, 1);
  mpz_init_set_d(i, 1);
  mpz_init_set_d(n_, n);
  mpz_init_set_d(tmp, 1);
  mpz_init_set_d(tmp2, 1);
  mpz_init_set_d(tmp3, 1);

  if ((k < 0) || (k > n))
    mpz_set_d(b, 0);
  else{
    k2 = min(k, (n - k));
    mpz_init_set_d(k_, k2);
    i2 = 1;
    while (i2 <= k2)
      {
	mpz_sub(tmp, n_, i);
	mpz_add_ui(tmp2, tmp, 1);
	mpz_mul(tmp3, b, tmp2);
	mpz_div(b, tmp3, i);
	mpz_add_ui(i, i, 1);
	i2++;
      }}
  mpz_class res(b);
  /*  mpz_clear(tmp);
      mpz_clear(tmp2);
      mpz_clear(tmp3);
      mpz_clear(k_);
      mpz_clear(n_);
      mpz_clear(b);
      mpz_clear(i);
  */  return (res);
}
//    b = ((b * (n - i + 1.0)) / i);
/*
  double	proba(double tma)
  {
  return ((1 / 5));
  }
*/

void	loi_binomial(double p, t_variable *var)
{
  double	n = 100;
  double	k = 0;
  //  double	p;
  double	res = 0;
  double	tmp;

  //  p = proba(tma);
  // p = 0.0412;
  while (k <= 50)
    {
      tmp = (coeff_binomial(n, k).get_d());
      tmp = (tmp * (pow(p, k)) * (pow((1 - p), (n - k))));
      // printf("coef pour k = %0.0f : %0.1f %%\n", k, tmp * 100);
      if (k == 0)
	var->o0[1] = tmp;
      if (k == 1)
	var->o1[1] = tmp;
      if (k == 2)
	var->o2[1] = tmp;
      if (k == 3)
	var->o3[1] = tmp;
      if (k == 4)
	var->o4[1] = tmp;
      if (k == 5)
	var->o5[1] = tmp;
      if (k == 6)
	var->o6[1] = tmp;
      if (k == 7)
	var->o7[1] = tmp;
      if (k > 7)
	var->o8[1] += tmp;
      res += tmp;
      k++;
    }
}
