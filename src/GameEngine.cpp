/*
** GameEngine.cpp for GameEngine in /home/sheol/my_git/gdl/src
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Tue May 20 15:51:01 2014 teddy fontaine
** Last update Mon Jun  9 10:23:43 2014 teddy fontaine
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
  if (!start(1280, 960, "My bomberman!"))
    return false;
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    return false;

  glm::mat4 projection;
  glm::mat4 transformation;
  projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
  transformation = glm::lookAt(glm::vec3(1, 1, 1), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);
  _shader.setUniform("color", glm::vec4(1, 1, 1, 1));
  if (scene() == false)
    return (false);

  return (true);
}

/*
 * Retourne la fenetre courante
 */
SDL_Window	*GameEngine::getWindow()
{
  return (_window);
}


/*
 * update des objets
 * gestion des events
 */
bool			GameEngine::update()
{
  size_t		i;
  size_t		x;
  std::vector<int>	objs;

  i = -1;
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  updateClock(_clock);
  updateInputs(_input);
  while (++i < _objects.size())
  {
    objs = _objects[i]->getObjs();
    x = -1;
    while (++x < objs.size())
    {
      if (objs[0] == 5)
      {
	if ((objs[1] < objs[2]) || (objs[1] == 0))
	  std::cout << objs[x] << std::endl;
      }
    }
    std::cout << "___________" << std::endl;
    _objects[i]->update(_clock, _input);
  }
  objs.clear();
  return (true);
}

/*
 * Affiche la scene a l'ecran
 */
void		GameEngine::draw()
{
  size_t	i;

  i = -1;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  while (++i < _objects.size())
    _objects[i]->draw(_shader, _clock);
  this->flush();
}

/*
 * Detruit les objets
 */
GameEngine::~GameEngine()
{
  size_t	i;

  i = -1;
  while (++i < _objects.size())
    delete _objects[i];
}
