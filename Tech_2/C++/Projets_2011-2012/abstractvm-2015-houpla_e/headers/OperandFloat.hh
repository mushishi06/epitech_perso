//
// Operand.hh for  in /home/emelyne/rendu/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Fri Feb  3 10:14:00 2012 Emelyne
// Last update Thu Feb  9 17:24:40 2012 Emelyne
//

#ifndef			OPERANDFLOAT_HH
#define			OPERANDFLOAT_HH

#include		"AOperand.hh"

namespace		Chipset
{

class			OperandFloat	:	public AOperand
{
  float			nb_;

public:
  OperandFloat(std::string const &str = "");
  virtual		~OperandFloat();

  float			getNb() const;
  void			setNb(const float &nb);

  virtual IOperand	*operator+(const IOperand &rhs) const;
  virtual IOperand	*operator-(const IOperand &rhs) const;
  virtual IOperand	*operator*(const IOperand &rhs) const;
  virtual IOperand	*operator/(const IOperand &rhs) const;
  virtual IOperand	*operator%(const IOperand &rhs) const;
};

}

#endif			/* OPERANDFLOAT_HH */
