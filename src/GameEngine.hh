/*
** GameEngine.hpp for partie graphique bomberman in /home/nguye_1/rendu/gdl
**
** Made by Alexandre NGUYEN
** Login   <nguye_1@epitech.net>
**
** Started on  Thu May 15 15:55:43 2014 Alexandre NGUYEN
** Last update Mon May 26 09:16:45 2014 teddy fontaine
*/

#include <Game.hh>
#include <SdlContext.hh>
#include "AObject.hh"
#include "Cube.hh"
#include "Carre.hh"
#include "Img.hh"

#ifndef GAMEENGINE_HH_
# define GAMEENGINE_HH_

class GameEngine : public gdl::Game, public gdl::SdlContext
{
  private:
    gdl::Clock			_clock;
    gdl::Input			_input;
    gdl::BasicShader		_shader;
    std::vector<AObject*>	_objects;
    Uint32			_start; // test de clock
    SDL_Surface			*loadImage(std::string filepath);
    void			applySurface(int x,int y, SDL_Surface* source,
						 SDL_Window* destination, SDL_Rect *clip);

  public:
    GameEngine();
    ~GameEngine();
    bool			initialize();
    bool			update();
    void			draw();
    bool			scene();
    bool			cubeDraw();
    bool			showHud();
    SDL_Window			*getWindow();
};

#endif /* !GAMEENGINE_HH_ */
