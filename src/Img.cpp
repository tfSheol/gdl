/*
** Img.cpp for gdl in /home/sheol/my_git/gdl/src
**
** Made by teddy fontaine
** Login   <sheol@epitech.net>
**
** Started on  Sat May 24 21:05:38 2014 teddy fontaine
** Last update Mon May 26 13:53:28 2014 teddy fontaine
*/

#include "Img.hh"

Img::Img(SDL_Window *window, std::string path)
{
  this->_filepath = path;
  this->_window = window;
}

Img::~Img()
{
}

/*
 * Initialise une image
 * color : _geometry.setColor(glm::vec4(R, G, B, 1));
 */
bool		Img::initialize(float x, float y, __attribute__((unused)) float z)
{
  this->_x = x;
  this->_y = y;
  if ((this->_img = this->loadImage()) == NULL)
  {
    fprintf(stdout,"echec de chargement du sprite (%s)\n", SDL_GetError());
    return (false);
  }
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
  this->applySurface();
  SDL_UpdateWindowSurface(this->_window);
  SDL_Delay(clock.getElapsed());
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
