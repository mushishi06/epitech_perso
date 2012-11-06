//
// Error.cpp for  in /home/emelyne/rendu/projet_abstractVM/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Wed Feb  8 12:06:27 2012 Emelyne
// Last update Fri Feb 10 10:42:48 2012 Emelyne
//

#include	"Error.hh"

Error::Error(int errcode)
  : _msg(buildMsg(errcode))
{
}

Error::~Error()	throw()
{
}

const char	*Error::what() const throw()
{
  return (_msg.c_str());
}

std::string	Error::buildMsg(int errcode)
{
  switch (errcode)
    {
    case EXIT:
      return ("Missing expression 'exit' ending the program");
    case POP:
      return ("Pop on an empty stack");
    case SYNTAX:
      return ("Syntax error");
    case UNKNOWN:
      return ("Unknown instruction");
    case ASSERT:
      return ("Assert instruction failed");
    case INVARG:
      return ("Invalid argument number");
    case DOMMODF:
      return ("modulo with a floating expression");
    case DOMMOD:
      return ("modulo by zero");
    case DOMDIV:
      return ("divided by zero");
    case OUTRANG:
      return ("Out of range exception");
    default:
      return ("An Error Happened");
    }
}
