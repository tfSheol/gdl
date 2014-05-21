/*
** GameEngine.hpp for partie graphique bomberman in /home/nguye_1/rendu/gdl
**
** Made by Alexandre NGUYEN
** Login   <nguye_1@epitech.net>
**
** Started on  Thu May 15 15:55:43 2014 Alexandre NGUYEN
** Last update Wed May 21 13:51:31 2014 teddy fontaine
*/

#include <Game.hh>
#include <SdlContext.hh>
#include "AObject.hh"
#include "Cube.hh"

#ifndef GAMEENGINE_HH_
# define GAMEENGINE_HH_

class GameEngine : public gdl::Game
{
  private:
    gdl::SdlContext		_context;
    gdl::Clock			_clock;
    gdl::Input			_input;
    gdl::BasicShader		_shader;
    std::vector<AObject*>	_objects;

  public:
    GameEngine();
    ~GameEngine();
    bool			initialize();
    bool			update();
    void			draw();
    bool			scene();
    bool			cubeDraw();
    bool			showHud();
};

#endif /* !GAMEENGINE_HH_ */
