/*
** Error.h for  in /home/emelyne/rendu/abstractVM
**
** Made by Emelyne
** Login   <emelyne@epitech.net>
**
** Started on  Fri Feb  3 13:05:46 2012 Emelyne
// Last update Fri Feb 10 10:43:00 2012 Emelyne
*/

#ifndef		ERROR_HH
#define		ERROR_HH

#include	<cstdlib>
#include	<stdexcept>
#include	<string>

#define		EXIT	1
#define		POP	2
#define		SYNTAX	3
#define		UNKNOWN	4
#define		ASSERT	5
#define		INVARG	6
#define		DOMMOD	7
#define		DOMMODF	8
#define		DOMDIV	9
#define		OUTRANG	10

class		Error	: public	std::exception
{
  std::string	_msg;
  std::string	buildMsg(int errcode);

public:
  Error(int errcode);
  ~Error()	throw();
  const char	*what() const throw();
};

#endif		/* ERROR_HH */
