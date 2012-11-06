//
// main.cpp for bomberman in /home/ss814/Documents/Epitech/git/bomberman
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Thu May 10 12:08:43 2012 Sampson SAVINEL
// Last update Sat Jun  2 10:54:41 2012 cedric santarelli
//

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<GL/gl.h>
#include	<GL/glu.h>
#include	<iostream>
#include	"Bomberman.hpp"
#include	"MyGame.hpp"
#include	"Background.hpp"

int		main(int argc, char *argv[], char *envp[]) {
  (void)argc;
  (void)argv;

  if (envp == NULL || getenv("PATH") == NULL) {
    std::cerr << "[ERROR] : Environment variable `PATH` missing." << std::endl;
  } else {
  MyGame	game;

  srand(time(NULL));
  game.run();
  }
  return (EXIT_SUCCESS);
}
