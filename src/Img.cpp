/*
** Img.cpp for gdl in /home/sheol/my_git/gdl/src
**
** Made by teddy fontaine
** Login   <sheol@epitech.net>
**
** Started on  Sat May 24 21:05:38 2014 teddy fontaine
** Last update Tue Jun  3 12:47:34 2014 teddy fontaine
*/

#include "Img.hh"

Img::Img(SDL_Window *window, std::string path)
{
  this->_filepath = path;
  this->_window = window;
}

Img::~Img()
{
//  SDL_FreeSurface(this->_img); //segfault!
}

/*
 * Initialise une image
 * color : _geometry.setColor(glm::vec4(R, G, B, 1));
 */
bool		Img::initialize(float x, float y, __attribute__((unused)) float z)
{
  this->_x = x;
  this->_y = y;
  this->_z = z;
/*  if ((this->_img = this->loadImage()) == NULL)
  {
    fprintf(stdout,"echec de chargement du sprite (%s)\n", SDL_GetError());
    return (false);
  }
  glGenTextures(1, &_texture);
  glBindTexture(GL_TEXTURE_2D, _texture);

  glTexImage2D(GL_TEXTURE_2D, 0, 3, _img->w, _img->h,
	       0, GL_BGR, GL_UNSIGNED_BYTE, _img->pixels);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  _geometry.pushVertex(glm::vec2(0, 0));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.build();*/

  if (_texture.load("./textures/brique.tga") == false)
  {
    std::cerr << "Cannot load the cube texture" << std::endl;
    return (false);
  }

//  z = getCamLocate();

  _geometry.pushVertex(glm::vec3(_x + 0.5, _y + -0.5, _z + 0.5));
  _geometry.pushVertex(glm::vec3(_x + 0.5, _y + 0.5, _z + 0.5));
  _geometry.pushVertex(glm::vec3(_x + -0.5, _y + 0.5, _z + 0.5));
  _geometry.pushVertex(glm::vec3(_x + -0.5, _y + -0.5, _z + 0.5));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.build();

/*  glBegin(GL_QUADS);

  glVertex2f(x, y);
  glVertex2f(x + 0.5, y -0.5);
  glVertex2f(x + 0.5, y + 0.5);
  glVertex2f(x + -0.5, y + -0.5);

  glEnd();

  glClear(GL_COLOR_BUFFER_BIT);*/
//  SwapBuffers();

/*  glPushMatrix();
  glTranslatef(-0.5f, -0.5f, 0.0f);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, (int)GL_MODULATE);
  glEnable(GL_TEXTURE_2D);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
  glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 1.0f);
  glTexCoord2f(1.0f, 1.0f); glVertex2f(1.0f, 1.0f);
  glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0f, 0.0f);
  glEnd();
  glPopMatrix();
  glEndList();
*/
  return (true);
}

/*
 * update de l'img
 */
void		Img::update(__attribute__((unused))gdl::Clock const &clock,
			    __attribute__((unused))gdl::Input &input)
{
}

/*
 * Dessine l'img
 */
void		Img::draw(__attribute__((unused))gdl::AShader &shader,
			  __attribute__((unused))gdl::Clock const &clock)
{
//  this->applySurface();
  _geometry.pushVertex(glm::vec3(_x + 0.5, _y + -0.5, _z + 0.5));
  _geometry.pushVertex(glm::vec3(_x + 0.5, _y + 0.5, _z + 0.5));
  _geometry.pushVertex(glm::vec3(_x + -0.5, _y + 0.5, _z + 0.5));
  _geometry.pushVertex(glm::vec3(_x + -0.5, _y + -0.5, _z + 0.5));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.build();
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_TRIANGLES);
}

/*
 *
 */
SDL_Surface	*Img::loadImage()
{
  SDL_Surface*	loadedImage;
  SDL_Surface*	optimizedImage;
  Uint32	colorkey;
  Uint32	currFormat;

  if ((loadedImage = SDL_LoadBMP(this->_filepath.c_str())) == NULL)
    return NULL;
  currFormat = loadedImage->format->format;
  if ((optimizedImage = SDL_ConvertSurfaceFormat(loadedImage, currFormat, 0)) == NULL)
    return NULL;
  SDL_FreeSurface(loadedImage);
  colorkey = SDL_MapRGB(optimizedImage->format, 0xFF, 0xFF, 0xFF);
  SDL_SetColorKey(optimizedImage, SDL_RLEACCEL, colorkey);
  return (optimizedImage);
}

/*
 *
 */
void		Img::applySurface()
{
  SDL_Rect	offset;

  offset.x = this->_x;
  offset.y = this->_y;
  SDL_BlitSurface(this->_img, NULL, SDL_GetWindowSurface(this->_window), &offset);
}
