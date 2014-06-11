/*
** GameEngine.cpp for GameEngine in /home/sheol/my_git/gdl/src
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Tue May 20 15:51:01 2014 teddy fontaine
** Last update Wed Jun 11 10:52:16 2014 teddy fontaine
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
  projection = glm::perspective(60.0f, 1280.0f / 960.0f, 0.1f, 100.0f);
  transformation = glm::lookAt(glm::vec3(1, 1, 6), glm::vec3(1, 1, 5), glm::vec3(0, 1, 0));

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
	if (((objs[1] < objs[2]) || (objs[1] == 0)) && objs[0] == 100)
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
void			GameEngine::draw()
{
  size_t		i;
  size_t		x;
  int			nb_player;
  std::vector<int>	objs;

  i = -1;
  nb_player = 0;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  i = -1;
  while (++i < _objects.size())
  {
    x = -1;
    objs = _objects[i]->getObjs();
    while (++x < objs.size())
    {
      if (objs[0] == 5 && ((objs[1] < objs[2]) || (objs[1] == 0)))
	nb_player = objs[1];
    }
    objs.clear();
  }
  if (nb_player == 1)
  {
    i = -1;
    glViewport(0, 0, 1280 / 2, 960);
    while (++i < _objects.size())
      _objects[i]->draw(_shader, _clock);
    i = -1;
    glViewport(1280 / 2, 0, 1280 / 2, 960);
    while (++i < _objects.size())
      _objects[i]->draw(_shader, _clock);
    _shader.setUniform("projection", glm::perspective(60.0f, (1280.0f / 2) / 960.0f, 0.1f, 100.0f));
  }
  else
  {
    i = -1;
    glViewport(0, 0, 1280, 960);
    while (++i < _objects.size())
      _objects[i]->draw(_shader, _clock);
    _shader.setUniform("projection", glm::perspective(60.0f, 1280.0f / 960.0f, 0.1f, 100.0f));
  }
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
