//
// SecondBomber.hpp for  in /home/jason/Tech2/ProgC++/Bomberman.Git/gitolite@89.92.92.67:bomberman.git/includes
//
// Made by Jason Leo
// Login   <jason@epitech.net>
//
// Started on  Mon May 21 20:51:42 2012 Jason Leo
// Last update Sun Jun  3 10:57:48 2012 jason leo
//

#ifndef		__SECONDBOMBER_HPP__
# define	__SECONDBOMBER_HPP__

# include	"Player.hpp"

class		SecondBomberman : public Player
{
public:
  SecondBomberman(float, float, e_type);
  ~SecondBomberman(void);

typedef struct	s_move
{
  gdl::Keys::Key input;
  void (SecondBomberman::*func)(std::deque<AObject*> &);
}		t_move;

  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &, std::deque<AObject*> &);
  void		draw(void);
  void		left(std::deque<AObject*> &);
  void		right(std::deque<AObject*> &);
  void		up(std::deque<AObject*> &);
  void		down(std::deque<AObject*> &);
  void          inc_bomb();
  void          take_bonus(int x, int y, std::deque<AObject*> &map);
  void          pos_bomb(std::deque<AObject*> &map);
};

#endif		/*!__SECONDBOMBER_HPP__*/
