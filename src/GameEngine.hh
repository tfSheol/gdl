/*
** GameEngine.hpp for partie graphique bomberman in /home/nguye_1/rendu/gdl
**
** Made by Alexandre NGUYEN
** Login   <nguye_1@epitech.net>
**
** Started on  Thu May 15 15:55:43 2014 Alexandre NGUYEN
** Last update Tue May 20 17:44:00 2014 teddy fontaine
*/

#include <Game.hh>
#include <SdlContext.hh>
#include "AObject.hh"
#include "cube.hpp"

#ifndef GAMEENGINE_HH_
# define GAMEENGINE_HH_

class GameEngine : public gdl::Game
{
  public:
    GameEngine();
    ~GameEngine();
    bool	initialize();
    bool	update();
    void	draw();

  private:
    gdl::SdlContext _context;
    gdl::Clock _clock;
    gdl::Input _input;
    gdl::BasicShader _shader;
    std::vector<AObject*> _objects;
};

#endif /* GAMEENGINE_HH_ */
