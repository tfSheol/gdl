/*
** GameEngine.cpp for GameEngine in /home/sheol/my_git/gdl/src
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Tue May 20 15:51:01 2014 teddy fontaine
// Last update Thu May 22 15:47:52 2014 Alexandre NGUYEN
*/

#include <iostream>
#include <string>
#include "GameEngine.hh"

GameEngine::GameEngine()
{
}

/*
 * Initialisation de la fenetre
 * Initialisation de la camera
 * Draw de 3 cubes par SceneDraw::scene()
 */
bool		GameEngine::initialize()
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
  transformation = glm::lookAt(glm::vec3(0, 3, -3), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));

  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);

  SDL_Surface	*surface;

  if ((surface = SDL_LoadBMP("./textures/pack_images_sdz/icone.bmp")) == NULL)
    std::cerr << "Fail to load .bmp" << std::endl;

  if (this->scene() == false)
    return (false);

  return (true);
}

/*
 * update des objets
 * gestion des events
 */
bool		GameEngine::update()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  glm::ivec2 pos;
  pos = _input.getMousePosition();

  std::cout << (int)pos[0] << std::endl;
  std::cout << (int)pos[1] << std::endl;
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->update(_clock, _input);
  return true;
}

/*
 * Affiche la scene a l'ecran
 */
void		GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_shader, _clock);
  _context.flush();
}

/*
 * Detruit les objets
 */
GameEngine::~GameEngine()
{
  for (size_t i = 0; i < _objects.size(); ++i)
    delete _objects[i];
}
