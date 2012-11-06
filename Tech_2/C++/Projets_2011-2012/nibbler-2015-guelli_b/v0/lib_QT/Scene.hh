//
// Scene.hh for  in /home/moreno_i//afs/renduLocal/projets/nibbler/lib_QT
//
// Made by igor morenosemedo
// Login   <moreno_i@epitech.net>
//
// Started on  Sat Mar 17 15:07:08 2012 igor morenosemedo
// Last update Sun Mar 18 00:24:21 2012 igor morenosemedo
//

#ifndef	__SCENE_HH_
#define	__SCENE_HH_

#include <QKeyEvent>
#include <QtGui>
#include "IEvent.hh"

class Scene : public QGraphicsScene
{
 Q_OBJECT

public:
  explicit Scene(IEvent &eventManager, unsigned int timeout);
  void	keyPressEvent(QKeyEvent *event);

private:
  IEvent		*_event;

public slots:
  void	timeout_func();
};

#endif
