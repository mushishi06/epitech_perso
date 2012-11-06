##
## Makefile for  in /home/moreno_i//afs/renduLocal/projets/nibbler
##
## Made by igor morenosemedo
## Login   <moreno_i@epitech.net>
##
## Started on  Thu Mar 15 20:01:48 2012 igor morenosemedo
## Last update Sun Mar 18 01:34:14 2012 badrane guellim
##

NAME		=	lib_nibbler_SFML.so

SRC		=	DisplayModule.cpp

OBJ		=	$(SRC:.cpp=.o)

CC		=	g++

CPPFLAGS	=	-W -Wextra -Wall -Werror -I..

LDFLAGS		=	-lsfml-graphics -lsfml-window -lsfml-system

RM		=	rm -f

all		:	$(OBJ)
			$(CC) -fPIC -c $(CPPFLAGS) $(SRC)
			$(CC) -shared -o $(NAME) $(CPPFLAGS) $(OBJ) $(LDFLAGS)

clean		:
			$(RM) *~ *\# *.o

fclean		:	clean
		 	$(RM) $(NAME)

re		:	fclean all
