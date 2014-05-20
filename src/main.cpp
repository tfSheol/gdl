/*
** main.cpp for main in /home/sheol/libgdl/LibBomberman_linux_x64
**
** Made by Teddy Fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Tue May 13 16:05:06 2014 Teddy Fontaine
** Last update Tue May 20 14:52:19 2014 teddy fontaine
*/

#include <cstdlib>
#include "GameEngine.hpp"
#include "cube.hpp"

int		main()
{
  GameEngine	*engine = new GameEngine();

  if (engine->initialize() == false)
    return (EXIT_FAILURE);
  while (engine->update() == true)
    engine->draw();
  delete engine;
  return EXIT_SUCCESS;
}
