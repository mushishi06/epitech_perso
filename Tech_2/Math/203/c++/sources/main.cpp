//
// main.cpp for 203hotline in /home/belia-_r/afs/epitech_perso/Tech_2/Math/203/c++
//
// Made by romain belia-bourgeois
// Login   <belia-_r@epitech.net>
//
// Started on  Sat Mar 23 20:53:43 2013 romain belia-bourgeois
// Last update Sat Jun  8 19:51:58 2013 romain belia-bourgeois
//

#include	<iostream>
#include	<string>
#include	<sstream>
#include	<cmath>
#include	<gmpxx.h>


template<typename T>
T StringToNumber(const std::string& numberAsString)
{
  T valor;

  std::stringstream stream(numberAsString);
  stream >> valor;

  return valor;
}

long double MpzToNumber(mpz_t& numberAsString)
{
  long double valor;

  std::stringstream stream;
  stream << numberAsString;
  stream >> valor;

  return valor;
}

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

double	proba(double tma)
{
  return ((1 / 5));
}

void	loi_binomial(double tma)
{
  double	n = 100;
  double	k = 0;
  double	p;
  double	res = 0;
  double	tmp;

  //  p = proba(tma);
  p = 0.0412;
  std::cout << "proba : " << p << std::endl;
  while (k <= 50)
    {
      tmp = (coeff_binomial(n, k).get_d());
      tmp = (tmp * (pow(p, k)) * (pow((1 - p), (n - k))));
      std::cout << "coef pour k = " << k << " : " << tmp << std::endl;
      res += tmp;
      k++;
    }
  res *= 100;
  std::cout.precision(130);
  std::cout << "total probabilite d’encombrement : " << res << " %" << std::endl;
}

int		main(int ac, char **av)
{
  if (ac >= 3)
    {
      double nb1 = StringToNumber<double>(av[1]);
      double nb2 = StringToNumber<double>(av[2]);
      mpz_class	coeff_bi;

      coeff_bi = coeff_binomial(nb1, nb2);
      std::cout.precision(50);
      std::cout << "combinaison de " << nb1 << " parmi " << nb2 << " : " << coeff_bi << std::endl;
    }
  else if (ac == 2)
    {
      double nb1 = StringToNumber<double>(av[1]);
      loi_binomial(nb1);
    }
}
