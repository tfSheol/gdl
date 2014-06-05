//
// Joystick.cpp for  in /home/peyrot_m/rendu/cpp_bomberman/Sources
//
// Made by peyrot_m
// Login   <peyrot_m@epitech.net>
//
// Started on  Sat May 31 14:59:53 2014 peyrot_m
// Last update Wed Jun  4 12:55:10 2014 Alexandre NGUYEN
//

#include "Joystick.hh"

Joystick::Joystick()
{
  if ( SDL_InitSubSystem ( SDL_INIT_JOYSTICK ) < 0)
    throw MyException("SDL ERROR: JOYSTICK");
  this->click_a = 0;
}

Joystick::~Joystick()
{
}

int	Joystick::Joystick_check()
{
  return (SDL_NumJoysticks());
}

int	Joystick::Joystick_for_menu(glm::ivec2 new_pos)
{
  this->pos = new_pos;
  this->click_a = 0;
  this->click_b = 0;
  if (this->Joystick_check() == 0)
    return (0);
  else
    {
      if ((this->joy1 = SDL_JoystickOpen(0)) == NULL)
	throw MyException("Error: gamepad 1");
      if (this->Joystick_check() == 2)
	if ((this->joy2 = SDL_JoystickOpen(1)) == NULL)
	  throw MyException("Error: gamepad 2");
      return (this->Joystick_check());
    }
}

int	Joystick::Joystick_for_game()
{
  if (this->Joystick_check() == 0)
    return (0);
  else
    {
      if ((this->joy1 = SDL_JoystickOpen(0)) == NULL)
	throw MyException("Error: gamepad 1");
      if (this->Joystick_check() == 2)
	if ((this->joy2 = SDL_JoystickOpen(1)) == NULL)
	  throw MyException("Error: gamepad 2");
      return (this->Joystick_check());
    }
}

glm::ivec2		Joystick::Joystick_new_pos()
{
  SDL_JoystickUpdate();
  unsigned int a = 0;
  unsigned int b = 0;
  unsigned int a_p2 = 0;
  unsigned int b_p2 = 0;
  Sint16 x_move, y_move, rtrigger,
    x_move_p2, y_move_p2, rtrigger_p2;

  rtrigger = SDL_JoystickGetAxis(this->joy1,5);
  x_move = SDL_JoystickGetAxis(this->joy1,0);
  y_move = SDL_JoystickGetAxis(this->joy1,1);
  a = SDL_JoystickGetButton (this->joy1, 0);
  b = SDL_JoystickGetButton (this->joy1, 1);
  if (this->Joystick_check() == 2)
    {
      rtrigger_p2 = SDL_JoystickGetAxis(this->joy2,5);
      x_move_p2 = SDL_JoystickGetAxis(this->joy2,0);
      y_move_p2 = SDL_JoystickGetAxis(this->joy2,1);
      a_p2 = SDL_JoystickGetButton (this->joy2, 0);
      b_p2 = SDL_JoystickGetButton (this->joy2, 1);
    }
  this->pos[1] +=  ((y_move/5000 * (1 + (rtrigger + 32768) / 8000)) +
		    (y_move_p2/5000 * (1 + (rtrigger_p2 + 32768) / 8000)));
  this->pos[0] +=  ((x_move/5000 * (1 + (rtrigger_p2 + 32768) / 8000)) +
		    (x_move_p2/5000 * (1 + (rtrigger_p2 + 32768) / 8000))) / 3;
  if (a == 1 || a_p2 == 1)
    this->click_a = 1;
  else
    this->click_a = 0;
  if (b == 1 || b_p2 == 1)
    this->click_b = 1;
  else
    this->click_b = 0;
  return (this->pos);
}

int		Joystick::get_button_click_a()
{
  return (this->click_a);
}

int		Joystick::get_button_click_b()
{
  return (this->click_a);
}

SDL_Joystick	*Joystick::getJoy1()
{
  return (this->joy1);
}

SDL_Joystick	*Joystick::getJoy2()
{
  return (this->joy2);
}
