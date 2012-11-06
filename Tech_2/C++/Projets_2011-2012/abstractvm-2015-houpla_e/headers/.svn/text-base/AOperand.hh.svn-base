//
// AOpreand.hh for  in /home/emelyne/rendu/projet_abstractVM/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Wed Feb  8 15:13:03 2012 Emelyne
// Last update Fri Feb 10 09:36:36 2012 Emelyne
//

#ifndef			AOPERAND_HH
#define			AOPERAND_HH

#include                <sstream>
#include		<cstdlib>
#include                <iostream>
#include                "Error.hh"
#include		"IOperand.hh"

namespace		Chipset
{

class			AOperand	:	public IOperand
{
  std::string           str_;
  int                   prec_;
  eOperandType          type_;

public:
  AOperand(std::string const &str = "");
  virtual		~AOperand();

  virtual std::string const     &toString() const;
  virtual int           getPrecision() const;
  virtual eOperandType  getType() const;
  void                  setPrecision(int);
  void                  setType(eOperandType);
  void			setString(const std::string &);
  void			dynamicCast(IOperand *, double);

  virtual IOperand      *operator+(const IOperand &rhs) const = 0;
  virtual IOperand      *operator-(const IOperand &rhs) const = 0;
  virtual IOperand      *operator*(const IOperand &rhs) const = 0;
  virtual IOperand      *operator/(const IOperand &rhs) const = 0;
  virtual IOperand      *operator%(const IOperand &rhs) const = 0;
};

}

#endif			/* AOPERAND_HH */
