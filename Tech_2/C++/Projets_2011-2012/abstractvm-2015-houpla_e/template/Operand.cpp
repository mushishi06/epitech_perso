//
// Operand.cpp for  in /home/emelyne/rendu/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Fri Feb  3 21:49:44 2012 Emelyne
// Last update Wed Feb  8 10:05:39 2012 Emelyne
//

#include	<sstream>
#include	"Operand.hh"

template<>
Operand<char>::Operand(const std::string &str)
  : str_(str)
{
  std::istringstream iss(str);

  iss >> nb_;
  prec_ = 0;
  type_ = Int8;
}

template<>
Operand<short>::Operand(const std::string &str)
  : str_(str)
{
  std::istringstream iss(str);

  iss >> nb_;
  prec_ = 1;
  type_ = Int16;
}

template<>
Operand<int>::Operand(const std::string &str)
  : str_(str)
{
  std::istringstream iss(str);

  iss >> nb_;
  prec_ = 2;
  type_ = Int32;
}

template<>
Operand<float>::Operand(const std::string &str)
  : str_(str)
{
  std::istringstream iss(str);

  iss >> nb_;
  prec_ = 3;
  type_ = Float;
}

template<>
Operand<double>::Operand(const std::string &str)
  : str_(str)
{
  std::istringstream iss(str);

  iss >> nb_;
  prec_ = 4;
  type_ = Double;
}

template<typename T>
Operand<T>::~Operand()
{
}

template<typename T>
std::string const		&Operand<T>::toString() const
{
  return (this->str_);
}

template<typename T>
T				Operand<T>::getNb() const
{
  return (this->nb_);
}

template<typename T>
int				Operand<T>::getPrecision() const
{
  return (this->prec_);
}

template<typename T>
eOperandType			Operand<T>::getType() const
{
  return (this->type_);
}

template<typename T>
void				Operand<T>::setPrecision(int pre)
{
  this->prec_ = pre;
}

template<typename T>
void				Operand<T>::setType(eOperandType pre)
{
  this->type_ = pre;
}

template<typename T>
void				Operand<T>::setNb(const T &nb)
{
  std::ostringstream		oss;

  oss << nb;
  this->str_.assign(oss.str());
  this->nb_ = nb;
}

template<typename T>
IOperand			*Operand<T>::operator+(const IOperand &rhs) const
{
  IOperand			*res = new Operand<T>(rhs.toString());
  std::istringstream		iss(rhs.toString());
  T				tmp;

  if (this->getPrecision() > rhs.getPrecision())
    {
      dynamic_cast<Operand*>(res)->setPrecision(rhs.getPrecision());
      dynamic_cast<Operand*>(res)->setType(rhs.getType());
    }
  iss >> tmp;
  dynamic_cast<Operand*>(res)->setNb(this->getNb() + tmp);
  return (res);
}

template<typename T>
IOperand			*Operand<T>::operator-(const IOperand &rhs) const
{
  IOperand			*res = new Operand<T>(rhs.toString());
  std::istringstream		iss(rhs.toString());
  T				tmp;

  if (this->getPrecision() > rhs.getPrecision())
    {
      dynamic_cast<Operand*>(res)->setPrecision(rhs.getPrecision());
      dynamic_cast<Operand*>(res)->setType(rhs.getType());
    }
  iss >> tmp;
  dynamic_cast<Operand*>(res)->setNb(this->getNb() - tmp);
  return (res);
}

template<typename T>
IOperand			*Operand<T>::operator*(const IOperand &rhs) const
{
  IOperand			*res = new Operand<T>(rhs.toString());
  std::istringstream		iss(rhs.toString());
  T				tmp;

  if (this->getPrecision() > rhs.getPrecision())
    {
      dynamic_cast<Operand*>(res)->setPrecision(rhs.getPrecision());
      dynamic_cast<Operand*>(res)->setType(rhs.getType());
    }
  iss >> tmp;
  dynamic_cast<Operand*>(res)->setNb(this->getNb() * tmp);
  return (res);
}

template<typename T>
IOperand			*Operand<T>::operator/(const IOperand &rhs) const
{
  IOperand			*res = new Operand<T>(rhs.toString());
  std::istringstream		iss(rhs.toString());
  T				tmp;

try
  {
    iss >> tmp;
    if (tmp == 0)
      throw std::domain_error("domain_error, divided by zero");
    if (this->getPrecision() > rhs.getPrecision())
      {
	dynamic_cast<Operand*>(res)->setPrecision(rhs.getPrecision());
	dynamic_cast<Operand*>(res)->setType(rhs.getType());
      }
    dynamic_cast<Operand*>(res)->setNb(this->getNb() / tmp);
    return (res);
  }
 catch (const std::exception &e)
   {
     std::cerr << "std::exception : "<< e.what() << std::endl;
     delete res;
     abort();
   }
}

template<>
IOperand			*Operand<char>::operator%(const IOperand &rhs) const
{
  IOperand			*res = new Operand<char>(rhs.toString());
  std::istringstream		iss(rhs.toString());
  char				tmp;

try
  {
    iss >> tmp;
    if (tmp == 0)
      throw std::domain_error("domain_error, modulo by zero");
    if ((this->getType() == Float) || (this->getType() == Double))
      throw std::domain_error("modulo with a floating expression");
    if (this->getPrecision() > rhs.getPrecision())
      {
	dynamic_cast<Operand*>(res)->setPrecision(rhs.getPrecision());
	dynamic_cast<Operand*>(res)->setType(rhs.getType());
      }
    dynamic_cast<Operand*>(res)->setNb(this->getNb() % tmp);
    return (res);
  }
 catch (const std::exception &e)
   {
     std::cerr << "std::exception : "<< e.what() << std::endl;
     delete res;
     abort();
   }
}

template<>
IOperand			*Operand<short>::operator%(const IOperand &rhs) const
{
  IOperand			*res = new Operand<short>(rhs.toString());
  std::istringstream		iss(rhs.toString());
  short				tmp;

  try
    {
      iss >> tmp;
      if (tmp == 0)
	throw std::domain_error("domain_error, modulo by zero");
      if ((this->getType() == Float) || (this->getType() == Double))
	throw std::domain_error("modulo with a floating expression");
      if (this->getPrecision() > rhs.getPrecision())
	{
	  dynamic_cast<Operand*>(res)->setPrecision(rhs.getPrecision());
	  dynamic_cast<Operand*>(res)->setType(rhs.getType());
	}
      dynamic_cast<Operand*>(res)->setNb(this->getNb() % tmp);
      return (res);
    }
  catch (const std::exception &e)
    {
      std::cerr << "std::exception : "<< e.what() << std::endl;
      delete res;
      abort();
    }
}

template<>
IOperand			*Operand<int>::operator%(const IOperand &rhs) const
{
  IOperand			*res = new Operand<int>(rhs.toString());
  std::istringstream		iss(rhs.toString());
  int				tmp;

  try
    {
      iss >> tmp;
      if (tmp == 0)
	throw std::domain_error("domain_error, modulo by zero");
      if ((this->getType() == Float) || (this->getType() == Double))
	throw std::domain_error("modulo with a floating expression");
      if (this->getPrecision() > rhs.getPrecision())
	{
	  dynamic_cast<Operand*>(res)->setPrecision(rhs.getPrecision());
	  dynamic_cast<Operand*>(res)->setType(rhs.getType());
	}
      dynamic_cast<Operand*>(res)->setNb(this->getNb() % tmp);
      return (res);
    }
  catch (const std::exception &e)
    {
      std::cerr << "std::exception : "<< e.what() << std::endl;
      delete res;
      abort();
    }
}

template<>
IOperand			*Operand<float>::operator%(const IOperand &rhs) const
{
  try
    {
      throw std::domain_error("modulo with a floating expression");
    }
  catch (const std::exception &e)
    {
      std::cerr << "std::exception : "<< e.what() << std::endl;
      abort();
    }
}

template<>
IOperand			*Operand<double>::operator%(const IOperand &rhs) const
{
  try
    {
      throw std::domain_error("modulo with a floating expression");
    }
  catch (const std::exception &e)
    {
      std::cerr << "std::exception : "<< e.what() << std::endl;
      abort();
    }
}
