//
// IOperand.hh for  in /home/emelyne/rendu/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Fri Feb  3 10:06:15 2012 Emelyne
// Last update Sun Feb 12 15:43:58 2012 Emelyne
//

#ifndef			IOPERAND_HH
#define			IOPERAND_HH

#include		<string>

namespace		Chipset
{

typedef enum		eOperandType
  {
    Int8 = 0,
    Int16,
    Int32,
    Float,
    Double
  }			eOperandType;

class			IOperand
{
public:
  virtual std::string const	&toString() const = 0;
  virtual int		getPrecision() const = 0;
  virtual eOperandType	getType() const = 0;

  virtual IOperand	*operator+(const IOperand &rhs) const = 0;
  virtual IOperand	*operator-(const IOperand &rhs) const = 0;
  virtual IOperand	*operator*(const IOperand &rhs) const = 0;
  virtual IOperand	*operator/(const IOperand &rhs) const = 0;
  virtual IOperand	*operator%(const IOperand &rhs) const = 0;

  virtual		~IOperand() {}
};

}

#endif			/* IOPERAND_HH */
