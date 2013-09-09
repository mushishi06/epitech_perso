//
// ConsumerParser.hpp for EPITECH in /home/belia-_r
//
// Made by Romain BELIA-BOURGEOIS
// Login   <belia-_r@epitech.net>
//
// Started on  Mon Sep 09 12:35:38 2013 Romain BELIA-BOURGEOIS
// Last update Mon Sep  9 13:08:04 2013 romain belia-bourgeois
//

#ifndef			_CONSUMERPARSER_HPP_
# define		_CONSUMERPARSER_HPP_

class			ConsumerParser
{
private:
  ProducterStream &_ps;
  string	*flux = NULL;

public:
  ConsumerParser(ProducterStream &);
  ~ConsumerParser();

  inline bool	peekChar(char c);
  inline bool	readChar(char c);
  inline bool	readRange(char begin, char end);
  inline bool	beginCapture(std::string tag);
  inline bool	endCapture(std::string tag, std::string& out);
  bool	readText(char *text);
  bool	readEOF();
  bool	readUntil(char c);
  bool	readUntilEOF();
  bool	readInteger();
  bool	readIdentifier();

};

#endif			/* !_CONSUMERPARSER_HPP_ */
