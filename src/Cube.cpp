/*
** cube.cpp for cube in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Wed May 21 13:35:02 2014 teddy fontaine
** Last update Mon Jun  2 16:14:32 2014 teddy fontaine
*/

#include "Cube.hh"

Cube::Cube()
{
}

Cube::~Cube()
{
}

/*
 * Initialise un cube
 * color : _geometry.setColor(glm::vec4(R, G, B, 1));
 */
bool	Cube::initialize(float x, float y, float z)
{
  _speed = 10.0f;

  if (_texture.load("./textures/brique.tga") == false)
  {
    std::cerr << "Cannot load the cube texture" << std::endl;
    return (false);
  }

  _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + 0.5));
  _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + 0.5));
  _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + 0.5));
  _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + 0.5));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + -0.5));
  _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + -0.5));
  _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + -0.5));
  _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + -0.5));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + -0.5));
  _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + -0.5));
  _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + 0.5));
  _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + 0.5));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + 0.5));
  _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + 0.5));
  _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + -0.5));
  _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + -0.5));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + 0.5));
  _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + -0.5));
  _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + -0.5));
  _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + 0.5));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + -0.5));
  _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + 0.5));
  _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + 0.5));
  _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + -0.5));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.build();
  return (true);
}

bool	Cube::initialize(float x, float y, float z, float size_x, float size_y, float size_z)
{
  _speed = 10.0f;

  if (_texture.load("./textures/brique.tga") == false)
  {
    std::cerr << "Cannot load the cube texture" << std::endl;
    return (false);
  }

  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.build();
  return (true);
}

bool	Cube::initialize(float x, float y, float z, float size_x, float size_y, float size_z, std::string texture_name)
{
  _speed = 10.0f;

  if (_texture.load(texture_name) == false)
  {
    std::cerr << "Cannot load the cube texture" << std::endl;
    return (false);
  }

  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f)); //    /  /
  _geometry.pushUv(glm::vec2(0.0f, 1.0f)); //   +--+ |
  _geometry.pushUv(glm::vec2(1.0f, 1.0f)); //   |**|/
  _geometry.pushUv(glm::vec2(1.0f, 0.0f)); //   +--+

  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f)); //    /  /
  _geometry.pushUv(glm::vec2(1.0f, 1.0f)); //   +--+ |
  _geometry.pushUv(glm::vec2(0.0f, 1.0f)); // ->|  |/
  _geometry.pushUv(glm::vec2(0.0f, 0.0f)); //   +--+

  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f)); //    /  /
  _geometry.pushUv(glm::vec2(1.0f, 1.0f)); //   +--+*|
  _geometry.pushUv(glm::vec2(0.0f, 1.0f)); //   |  |/
  _geometry.pushUv(glm::vec2(0.0f, 0.0f)); //   +--+

  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f)); //    /**/
  _geometry.pushUv(glm::vec2(0.0f, 0.0f)); //   +--+ |
  _geometry.pushUv(glm::vec2(1.0f, 0.0f)); //   |  |/
  _geometry.pushUv(glm::vec2(1.0f, 1.0f)); //   +--+

  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.build();
  return (true);
}

/*
 * gestion des mouvements du cube
 */
void	Cube::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (input.getKey(SDLK_UP))
    translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_DOWN))
    translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_LEFT))
    translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_RIGHT))
    translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
}

/*
 * Dessine le cube
 */
void	Cube::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
