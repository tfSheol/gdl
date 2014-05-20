/*
** GameEngine.hpp for partie graphique bomberman in /home/nguye_1/rendu/gdl
**
** Made by Alexandre NGUYEN
** Login   <nguye_1@epitech.net>
**
** Started on  Thu May 15 15:55:43 2014 Alexandre NGUYEN
** Last update Tue May 20 15:08:53 2014 teddy fontaine
*/

#ifndef GAMEENGINE_HPP_
# define GAMEENGINE_HPP_

#include <Game.hh>
#include <SdlContext.hh>
#include "AObject.hpp"
#include "cube.hpp"

class GameEngine : public gdl::Game
{
  public:
    GameEngine()
    {
    }

    /*
     * Initialisation de la fenetre
     * Initialisation de la camera
     * Draw de 3 cubes
     */
    bool	initialize()
    {
      if (!_context.start(1280, 960, "My bomberman!"))
	return false;
      glEnable(GL_DEPTH_TEST);
      if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER)
	  || !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER)
	  || !_shader.build())
	return false;

      glm::mat4 projection;
      glm::mat4 transformation;
      projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
      transformation = glm::lookAt(glm::vec3(0, 11, -2), glm::vec3(0, 10, 0), glm::vec3(0, 1, 0));

      _shader.bind();
      _shader.setUniform("view", transformation);
      _shader.setUniform("projection", projection);

      /*
       * OBJS
       */
      AObject *cube1 = new Cube();
      AObject *cube2 = new Cube();
      AObject *cube3 = new Cube();

      if (cube1->initialize(0,0,0) == false)
	return (false);
      if (cube2->initialize(10,0,0) == false)
	return (false);
      if (cube3->initialize(0,10,0) == false)
	return (false);
      _objects.push_back(cube1);
      _objects.push_back(cube2);
      _objects.push_back(cube3);
      return true;
    }

    /*
     * update des objets
     * gestion des events
     */
    bool	update()
    {
      if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
	return false;
      _context.updateClock(_clock);
      _context.updateInputs(_input);
      for (size_t i = 0; i < _objects.size(); ++i)
	_objects[i]->update(_clock, _input);
      return true;
    }

    /*
     * Affiche la scene a l'ecran
     */
    void	draw()
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      _shader.bind();
      for (size_t i = 0; i < _objects.size(); ++i)
	_objects[i]->draw(_shader, _clock);
      _context.flush();
    }

    /*
     * Supprime les objets
     */
    ~GameEngine()
    {
      for (size_t i = 0; i < _objects.size(); ++i)
	delete _objects[i];
    }

  private:
    gdl::SdlContext _context;
    gdl::Clock _clock;
    gdl::Input _input;
    gdl::BasicShader _shader;
    std::vector<AObject*> _objects;
};

#endif /* GAMEENGINE_HPP */
