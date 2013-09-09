//
// ProducterStream.hpp for EPITECH in /home/belia-_r
//
// Made by Romain BELIA-BOURGEOIS
// Login   <belia-_r@epitech.net>
//
// Started on  Mon Sep 09 12:04:18 2013 Romain BELIA-BOURGEOIS
// Last update Mon Sep  9 12:13:28 2013 romain belia-bourgeois
//

#ifndef			_PRODUCTERSTREAM_HPP_
# define		_PRODUCTERSTREAM_HPP_

#include	<iostream>

class			ProducterStream
{
private:

  public:
  ProducterStream();
  ~ProducterStream();

  std::string	nextString();
  bool		loadFile(char *path);
  bool		loadStdin();

};

#endif			/* !_PRODUCTERSTREAM_HPP_ */
