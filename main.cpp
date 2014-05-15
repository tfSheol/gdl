/*
** main.cpp for main in /home/sheol/libgdl/LibBomberman_linux_x64
**
** Made by Teddy Fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Tue May 13 16:05:06 2014 Teddy Fontaine
// Last update Thu May 15 17:30:37 2014 Alexandre NGUYEN
*/

#include <cstdlib>
#include "GameEngine.hpp"

int main()
{
  // On cree son engine
  GameEngine engine;

  if (engine.initialize() == false)
    return (EXIT_FAILURE);
  while (engine.update() == true)
    engine.draw();
  return EXIT_SUCCESS;
}
