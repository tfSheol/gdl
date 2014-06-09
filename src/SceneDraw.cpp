/*
** SceneDraw.cpp for SceneDraw in /home/sheol/my_git/gdl/src
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Wed May 21 11:27:28 2014 teddy fontaine
** Last update Mon Jun  9 10:25:02 2014 teddy fontaine
*/

#include "GameEngine.hh"
#include <Model.hh>

/*
 * Draw la Scene
 */
bool		GameEngine::scene()
{
  AObject *cam = new Cam();

  if (cam->initialize(1, 1, 5) == false)
    return (false);
  _objects.push_back(cam);


/*  if (showHud() == false)
    return (false);*/
/*  if (cubeDraw() == false)
    return (false);*/

//  AObject *mod = new Mod("./assets/bomb.fbx");
//  AObject *mod1 = new Mod("./assets/bomb.fbx");
//  AObject *mod1 = new Bonus("./assets/quad.fbx");
//  AObject *player = new Bonus("./assets/maure.fbx");
  AObject *player0 = new Player(0, "./assets/marvin.fbm/test.tga");
  AObject *player1 = new Player(1, "./assets/marvin.fbm/Main_texture_diffuse2.tga");
  AObject *player2 = new Player(2, "./assets/marvin.fbm/Main_texture_diffuse2.tga");
  AObject *player3 = new Player(3, "./assets/marvin.fbm/Main_texture_diffuse2.tga");
  AObject *player4 = new Player(4, "./assets/marvin.fbm/Main_texture_diffuse2.tga");
  AObject *player5 = new Player(5, "./assets/marvin.fbm/Main_texture_diffuse2.tga");
  AObject *bonus0 = new Bonus("./assets/bomb.fbx");

  if (!bonus0->initialize(-1, 0, 0))
    return (false);
  if (!player0->initialize(-4, 0, 0))
    return (false);
  if (!player1->initialize(-2, 0, 0))
    return (false);
  if (!player2->initialize(0, 0, 0))
    return (false);
  if (!player3->initialize(2, 0, 0))
    return (false);
  if (!player4->initialize(4, 0, 0))
    return (false);
  if (!player5->initialize(6, 0, 0))
    return (false);

  _objects.push_back(bonus0);
  _objects.push_back(player0);
  _objects.push_back(player1);
  _objects.push_back(player2);
  _objects.push_back(player3);
  _objects.push_back(player4);
  _objects.push_back(player5);
  /* if (mod->initialize(1, 0, 0) == false)
    return (false);
  if (mod1->initialize(2, 0, 0) == false)
    return (false);
  if (player->initialize(0, 0, 1) == false)
  return (false);*/
/*  if (player4->initialize(-2, 0, 1) == false)
    return (false);
  if (player5->initialize(-2, 0, 1) == false)
  return (false);*/
/*  _objects.push_back(mod);
  _objects.push_back(mod1);
  _objects.push_back(player);*/
//  _objects.push_back(player4);
//  _objects.push_back(player5);

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
