//
// Joystick.hh for  in /home/peyrot_m/rendu/cpp_bomberman/Sources
//
// Made by peyrot_m
// Login   <peyrot_m@epitech.net>
//
// Started on  Sat May 31 15:02:00 2014 peyrot_m
// Last update Tue Jun  3 16:19:10 2014 Alexandre NGUYEN
//

#ifndef		JOYSTICK_HH_
# define	JOYSTICK_HH_

# include <SdlContext.hh>
# include <sstream>
# include "MyException.hh"

class		Joystick
{
private:

  SDL_Joystick*		joy1;
  SDL_Joystick*		joy2;
  glm::ivec2		pos;
  int			click_a;
  int			click_a_p2;
  int			click_b;
  int			click_b_p2;

public:

  Joystick();
  ~Joystick();

  int			Joystick_check();
  int			Joystick_for_menu(glm::ivec2 new_pos);
  int			Joystick_for_game();
  glm::ivec2		Joystick_new_pos();
  int			get_button_click_a();
  int			get_button_click_b();
  SDL_Joystick		*getJoy1();
  SDL_Joystick		*getJoy2();
};

#endif
