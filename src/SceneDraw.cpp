/*
** SceneDraw.cpp for SceneDraw in /home/sheol/my_git/gdl/src
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Wed May 21 11:27:28 2014 teddy fontaine
** Last update Thu Jun  5 14:48:03 2014 teddy fontaine
*/

#include "GameEngine.hh"
#include <Model.hh>

/*
 * Draw la Scene
 */
bool		GameEngine::scene()
{
  AObject *cam = new Cam();

  if (cam->initialize(1, 1, 1) == false)
    return (false);
  _objects.push_back(cam);


/*  if (showHud() == false)
    return (false);*/
/*  if (cubeDraw() == false)
    return (false);*/

  AObject *mod = new Mod("./assets/bomb.fbx");
//  AObject *mod1 = new Mod("./assets/bomb.fbx");
  AObject *mod1 = new Bonus("./assets/quad.fbx");
  AObject *player = new Player("./assets/marvin.fbx");
//  AObject *mod2 = new Mod("./assets/marvin.fbx");

  if (mod->initialize(0, 0, 0) == false)
    return (false);
  if (mod1->initialize(5, 1, 0) == false)
    return (false);
  if (player->initialize(0, 1, 1) == false)
    return (false);
  _objects.push_back(mod);
  _objects.push_back(mod1);
  _objects.push_back(player);

  return (true);
}

/*
 *
 */
bool		GameEngine::cubeDraw()
{
  AObject *cube1 = new Cube();
  // AObject *cube2 = new Cube();
  // AObject *cube3 = new Cube();
//  AObject *carre = new Carre();

  if (cube1->initialize(0,2,0) == false)
    return (false);
  // if (cube2->initialize(0,0,1.5,3,1,1) == false)
  //   return (false);
  // if (cube3->initialize(0,1,3,3,1,1, "./textures/play.tga") == false)
  //   return (false);
//  if (carre->initialize(0,3,0,4,3,1, "./textures/play.tga") == false)
//    return (false);
  _objects.push_back(cube1);
  // _objects.push_back(cube2);
  // _objects.push_back(cube3);
//  _objects.push_back(carre);

  return (true);
}

/*
 *
 */
bool		GameEngine::showHud()
{
  AObject *img = new Img(this->_window, "./img/test.bmp");
  AObject *img1 = new Img(this->_window, "./img/test.bmp");
  AObject *img2 = new Img(this->_window, "./img/test.bmp");

  if (img->initialize(0.0f, 0.0f, 0.0f) == false)
    return (false);
  if (img1->initialize(300.0f, 0.0f, 0.0f) == false)
    return (false);
  if (img2->initialize(0.0f, 300.0f, 0.0f) == false)
    return (false);
  _objects.push_back(img);
  _objects.push_back(img1);
  _objects.push_back(img2);
  return (true);
}
