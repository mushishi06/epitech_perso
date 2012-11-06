//
// Aintelligence.hpp for  in /home/jason/Tech2/ProgC++/bomberman-2015-savine_s/includes
//
// Made by Jason Leo
// Login   <jason@epitech.net>
//
// Started on  Mon May 21 13:53:39 2012 Jason Leo
// Last update Sun Jun  3 17:17:47 2012 guillaume francois
//

#ifndef		__AINTELLIGENCE_HPP__
# define	__AINTELLIGENCE_HPP__

# include	"Player.hpp"

class		Aintelligence : public Player
{
protected:

  void (Aintelligence::*reverse_mov)(std::deque<AObject*> &, int);

public:
  Aintelligence(float, float, e_type);
  ~Aintelligence(void);

  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &, std::deque<AObject*> &);
  void		draw(void);
  bool		found_player(Vector3f const &, std::deque<AObject*> &map);
  void		drop_bomb(std::deque<AObject*> &map);
  bool          safe(int x, int y, std::deque<AObject*> &map, int*);
  void		go_safe_place(std::deque<AObject*> &map);

  void		right_left(float, std::deque<AObject*> &map);
  void		go_left(std::deque<AObject*> &map, int);
  void		go_right(std::deque<AObject*> &map, int);

  void		up_down(float, std::deque<AObject*> &map);
  void		go_up(std::deque<AObject*> &map, int);
  void		go_down(std::deque<AObject*> &map, int);
  void          inc_bomb();
};

#endif		/*!_AINTELLIGENCE_HH_*/
