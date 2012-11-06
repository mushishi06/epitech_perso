//
// Snake.hh for  in /home/moreno_i//afs/renduLocal/projets/nibbler
//
// Made by igor morenosemedo
// Login   <moreno_i@epitech.net>
//
// Started on  Tue Mar 13 22:39:53 2012 igor morenosemedo
// Last update Sun Mar 18 00:38:49 2012 igor morenosemedo
//

#include	"IEvent.hh"
#include	"IDisplayModule.hh"

#ifndef		_SNAKE_HH_
# define	_SNAKE_HH_

#  define	MAPHEIGH	10
#  define	MAPWIDTH	10

#  define	SIZESNAKE	5

#  define	SPEEDUP		5
#  define	SPEEDSTART	100

#  define	WALLHEIGH	700
#  define	WALLWIDTH       700

#  define	S_DOWN		0
#  define	S_LEFT		1
#  define	S_UP		2
#  define	S_RIGHT		3

#  define	USAGE		"Usage : ./nibbler WIDTH HEIGHT [lib_name.so]"

class Snake : public IEvent
{
private:
  unsigned int		_sizeSnake;
  char			_whereImGoingTo;
  IDisplayModule	*_display;

  unsigned int		_mapWidth;
  unsigned int		_mapHeigh;
  unsigned int		_wallWidth;
  unsigned int		_wallHeigh;

  unsigned int		_points;
  s_coord		_key;

  std::string		_texture;
  s_coord		_textDim;

  std::deque<s_coord>	_snaAAAake;
  std::deque<s_coord>	_walls;

public:
  Snake(IDisplayModule *);
  Snake(const Snake &);
  virtual ~Snake();
  const Snake &operator=(const Snake &);

public:
  void KeyRight();
  void KeyLeft();
  void KeyEschap();
  void ChooseEvent();
  int  run();

private:
  void init_snaaAAake(unsigned int);
  bool Snake_nonSaaaake(const s_coord &);
  bool Where_is_Snake(const s_coord &);
  void KeyMove();
  void Print();

public:
  void		setMap(unsigned int, unsigned int);
  void		setWall(unsigned int, unsigned int);

public:
  char	getWhereImGoingTo() const;
  const IDisplayModule	*getDisplay() const;

  unsigned int	getMapWidth() const;
  unsigned int	getMapHeigh() const;
  unsigned int	getWallWidth() const;
  unsigned int	getWallHeigh() const;

  unsigned int	getSnakeSize() const;

  unsigned int	getPoints() const;
  const s_coord	&getKey() const;

  const   std::deque<s_coord> & getSnnaAAAake() const;

};

#endif
