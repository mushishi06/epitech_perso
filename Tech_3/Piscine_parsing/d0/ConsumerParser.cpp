//
// ConsumerParser.hpp for EPITECH in /home/belia-_r
//
// Made by Romain BELIA-BOURGEOIS
// Login   <belia-_r@epitech.net>
//
// Started on  Mon Sep 09 12:35:38 2013 Romain BELIA-BOURGEOIS
// Last update Mon Sep  9 12:51:01 2013 romain belia-bourgeois
//

#include			"ConsumerParser.hpp"

ConsumerParser::ConsumerParser(ProducterStream &ps) : _ps(ps)
{
}

ConsumerParser::~ConsumerParser()
{
}

inline bool	ConsumerParser::peekChar(char c)
{
}

inline bool	ConsumerParser::readChar(char c)
{
}

inline bool	ConsumerParser::readRange(char begin, char end)
{
}

inline bool	ConsumerParser::beginCapture(std::string tag)
{
}

inline bool	ConsumerParser::endCapture(std::string tag, std::string& out)
{
}

bool	ConsumerParser::readText(char *text)
{
}

bool	ConsumerParser::readEOF()
{
}

bool	ConsumerParser::readUntil(char c)
{
}

bool	ConsumerParser::readUntilEOF()
{
}

bool	ConsumerParser::readInteger()
{
}

bool	ConsumerParser::readIdentifier()
{
}
