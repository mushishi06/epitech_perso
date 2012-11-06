//
// Bomber.hpp for  in /home/jason/Tech2/ProgC++/bomberman-2015-savine_s/includes
//
// Made by Jason Leo
// Login   <jason@epitech.net>
//
// Started on  Mon May 21 13:35:15 2012 Jason Leo
// Last update Sun Jun  3 11:13:48 2012 jason leo
//

#ifndef		__BOMBER_HPP__
# define	__BOMBER_HPP__

# include	"Player.hpp"

class		Bomberman : public Player
{
public:
  Bomberman(float, float, e_type);
  ~Bomberman(void);

  typedef struct s_move
  {
    gdl::Keys::Key input;
    void (Bomberman::*func)(std::deque<AObject*> &);
  }t_move;

  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &, std::deque<AObject*> &);
  void		draw(void);
  void		unload(void);
  void		left(std::deque<AObject*> &);
  void		right(std::deque<AObject*> &);
  void		up(std::deque<AObject*> &);
  void		down(std::deque<AObject*> &);
  void          inc_bomb();
  void          take_bonus(int x, int y, std::deque<AObject*> &map);
  void          pos_bomb(std::deque<AObject*> &map);
};

#endif		/*!__BOMBER_HPP__*/
