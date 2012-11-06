//
// Operand.hh for  in /home/emelyne/rendu/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Fri Feb  3 10:14:00 2012 Emelyne
// Last update Thu Feb  9 17:24:30 2012 Emelyne
//

#ifndef			OPERANDINT32_HH
#define			OPERANDINT32_HH

#include		"AOperand.hh"

namespace		Chipset
{

class			OperandInt32	:	public AOperand
{
  int			nb_;

public:
  OperandInt32(std::string const &str = "");
  virtual		~OperandInt32();

  int			getNb() const;
  void			setNb(const int &nb);

  virtual IOperand	*operator+(const IOperand &rhs) const;
  virtual IOperand	*operator-(const IOperand &rhs) const;
  virtual IOperand	*operator*(const IOperand &rhs) const;
  virtual IOperand	*operator/(const IOperand &rhs) const;
  virtual IOperand	*operator%(const IOperand &rhs) const;
};

}

#endif			/* OPERANDINT32_HH */
