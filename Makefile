##
## Makefile for gdl in /home/sheol/libgdl/LibBomberman_linux_x64
##
## Made by Teddy Fontaine
## Login   <sheol@epitech.net>
##
## Started on  Tue May 13 16:04:20 2014 Teddy Fontaine
## Last update Sat Jun  7 15:16:10 2014 teddy fontaine
##

BIN		= test_graph

CC		= g++

RM		= rm -rf

PATH_SRC	= ./src

GDL		= -I./includes -L./libs -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread -Wl,--rpath=./libs/

CPPFLAGS	= -g3 -W -Wall -Wextra -Werror $(GDL)

LDFLAGS		+= $(CPPFLAGS)

SRCS		= $(PATH_SRC)/main.cpp		\
		  $(PATH_SRC)/GameEngine.cpp	\
		  $(PATH_SRC)/AObject.cpp	\
		  $(PATH_SRC)/Img.cpp		\
		  $(PATH_SRC)/SceneDraw.cpp	\
		  $(PATH_SRC)/Cube.cpp		\
		  $(PATH_SRC)/Carre.cpp		\
		  $(PATH_SRC)/Mod.cpp		\
		  $(PATH_SRC)/Player.cpp	\
		  $(PATH_SRC)/Cam.cpp		\
		  $(PATH_SRC)/Bonus.cpp		\
		  $(PATH_SRC)/Joystick.cpp	\

OBJS		= $(SRCS:.cpp=.o)


$(BIN):		$(OBJS)
		$(CC) -o $(BIN) $(OBJS) $(LDFLAGS)

all:		$(BIN)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(BIN)

re:		fclean all
