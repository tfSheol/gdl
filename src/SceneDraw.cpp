/*
** SceneDraw.cpp for SceneDraw in /home/sheol/my_git/gdl/src
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Wed May 21 11:27:28 2014 teddy fontaine
** Last update Wed May 21 13:22:49 2014 teddy fontaine
*/

#include "GameEngine.hh"

/*
 * Draw la Scene
 */
bool		GameEngine::scene()
{
  if (this->cubeDraw() == false)
    return (false);
  if (this->showHud() == false)
    return (false);
  return (true);
}

bool		GameEngine::cubeDraw()
{
  AObject *cube1 = new Cube();

  if (cube1->initialize(0,0,0) == false)
    return (false);
  _objects.push_back(cube1);

  return (true);
}

bool		GameEngine::showHud()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0f, 1280, 960, 0.0f, 0.0f, 1.0f);

  return (true);
}
