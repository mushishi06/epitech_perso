//
// Player.hpp for  in /home/jason/Tech2/ProgC++/bomberman-2015-savine_s/includes
//
// Made by Jason Leo
// Login   <jason@epitech.net>
//
// Started on  Mon May 21 12:30:14 2012 Jason Leo
// Last update Sun Jun  3 12:28:14 2012 guillaume francois
//

#ifndef		__PLAYER_HPP__
# define	__PLAYER_HPP__

# include	<GL/gl.h>
# include	<GL/glu.h>
# include	<stdlib.h>
# include	"Model.hpp"
# include	"AObject.hpp"

class		Player : public AObject
{
protected:
  gdl::Model	model_;
  int		nb_bomb_;
  int		tot_bomb_;
  float		speed_;
  int		isWalk;
  int		port;
  bool		posed_;
  bool		run_;

public:
  Player(float, float, e_type);
  ~Player(void);

  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &, std::deque<AObject*> &);
  void		draw(void);
  int		getNbBomb(void)const;
  void		setNbBomb(int);
  int		getTotBomb(void)const;
  void		setTotBomb(int);
  float		getSpeed(void)const;
  void		setSpeed(int);
  int		getRange(void)const;
  void		setRange(int);
};

#endif		/*!__PLAYER_HPP__*/
