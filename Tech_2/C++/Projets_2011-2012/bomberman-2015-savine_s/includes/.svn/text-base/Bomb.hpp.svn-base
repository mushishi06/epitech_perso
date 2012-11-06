//
// Bomb.hpp for bomberman in /home/ha-tam_l/Desktop/projet/bomberman/git_bomber
//
// Made by laurent ha-tam-dan
// Login   <ha-tam_l@epitech.net>
//
// Started on  Thu May 24 18:14:35 2012 laurent ha-tam-dan
// Last update Sun Jun  3 12:33:25 2012 guillaume francois
//

#ifndef		__BOMB_HPP__
# define	__BOMB_HPP__

# include	<stdlib.h>
# include	"Clock.hpp"
# include	"Object.hpp"
# include	"Aintelligence.hpp"

class		Bomb : public AObject
{
private:
  gdl::Model	model_;
  gdl::Clock	time_;
  int		port;
  AObject	*pos_;
  int		player_;
  int		danger_;

public:
  Bomb(float, float, e_type, int, AObject*, int);
  ~Bomb(void);

  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &, std::deque<AObject*> &);
  void		draw(void);
  void		detect_explosion(int x, int y, int *dir, std::deque<AObject*> &map);
  void          explosion(std::deque<AObject*> &map);
  bool          can_expl(int x, int y, int *dir, std::deque<AObject*> &map);
  void          add_explo(float x, float y, std::deque<AObject*> &map);
  void          add_bonus(float x, float y, e_type bonus_type,  std::deque<AObject*> &map, unsigned int *i);
  float		getTime(void)const;
  void		setTime(float);
  int		getPlayer(void)const;
  void		setPlayer(int);
};

#endif	/* !__BOMB_HPP__ */
