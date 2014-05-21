/*
** SceneDraw.cpp for SceneDraw in /home/sheol/my_git/gdl/src
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Wed May 21 11:27:28 2014 teddy fontaine
// Last update Wed May 21 15:12:09 2014 Alexandre NGUYEN
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
  AObject *cube2 = new Cube();
  AObject *cube3 = new Cube();

  if (cube1->initialize(2.5,0,0) == false)
    return (false);
  if (cube2->initialize(0,0,1.5,3,1,1) == false)
    return (false);
  if (cube3->initialize(0,1,3,3,1,1, "./textures/play.tga") == false)
    return (false);
  _objects.push_back(cube1);
  _objects.push_back(cube2);
  _objects.push_back(cube3);

  return (true);
}

bool		GameEngine::showHud()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0f, 1280, 960, 0.0f, 0.0f, 1.0f);

  return (true);
}
