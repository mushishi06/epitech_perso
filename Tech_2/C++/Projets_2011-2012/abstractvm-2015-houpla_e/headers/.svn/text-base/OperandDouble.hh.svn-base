//
// Operand.hh for  in /home/emelyne/rendu/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Fri Feb  3 10:14:00 2012 Emelyne
// Last update Thu Feb  9 17:24:49 2012 Emelyne
//

#ifndef			OPERANDDOUBLE_HH
#define			OPERANDDOUBLE_HH

#include		"AOperand.hh"

namespace		Chipset
{

class			OperandDouble	:	public AOperand
{
  double		nb_;

public:
  OperandDouble(std::string const &str = "");
  virtual		~OperandDouble();

  double		getNb() const;
  void			setNb(const double &nb);

  virtual IOperand	*operator+(const IOperand &rhs) const;
  virtual IOperand	*operator-(const IOperand &rhs) const;
  virtual IOperand	*operator*(const IOperand &rhs) const;
  virtual IOperand	*operator/(const IOperand &rhs) const;
  virtual IOperand	*operator%(const IOperand &rhs) const;
};

}

#endif			/* OPERANDDOUBLE_HH */
