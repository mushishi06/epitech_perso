//
// Scene.cpp for  in /home/moreno_i//afs/renduLocal/projets/nibbler/lib_QT
//
// Made by igor morenosemedo
// Login   <moreno_i@epitech.net>
//
// Started on  Sat Mar 17 15:07:40 2012 igor morenosemedo
// Last update Sat Mar 17 15:09:16 2012 igor morenosemedo
//

#include <iostream>
#include "Scene.hh"

Scene::Scene(IEvent &eventManager, unsigned int timeout)
{
  if (timeout == 0)
    timeout = 350;
  this->_event = &eventManager;
  QTimer::singleShot(timeout, this, SLOT(timeout_func()));
}

void	Scene::keyPressEvent(QKeyEvent *event)
{
  if(event->key() == Qt::Key_Left)
    this->_event->KeyLeft();
  else if(event->key() == Qt::Key_Right)
    this->_event->KeyRight();
  else if(event->key() == Qt::Key_Escape)
    this->_event->KeyEschap();
}

void	Scene::timeout_func()
{
  this->_event->ChooseEvent();
}
