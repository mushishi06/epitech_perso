##
## Makefile for 205QI in /home/belia-_r/afs/epitech_perso/Tech_2/Math/205
## 
## Made by romain belia-bourgeois
## Login   <belia-_r@epitech.net>
## 
## Started on  Thu May  2 22:17:57 2013 romain belia-bourgeois
## Last update Sun May  5 13:48:30 2013 romain belia-bourgeois
##

NAME 	= 205QI

SRCS	= xmalloc.c	\
	main.c		\
	gauss.c		\
	sdl/fleche.c	\
	sdl/axes.c	\
	sdl/fonctions.c	\

OPTI	= -O2

IPATH   = -I./include -I./src/proc
OBJOPT  = $(OPTI) #-W -Wall
CFLAGS  = $(OBJOPT) $(IPATH)
CXXFLAGS= $(CFLAGS)

LPATH   = -L. -lm `sdl-config --cflags --libs` -lSDL_gfx

RM 	= /bin/rm -f

CC 	= g++

OBJS 	= $(SRCS:.c=.o)

.PHONY		: clean fclean re

all		: $(NAME)

$(NAME)		: $(OBJS)
	$(CC) $(OBJS) $(LPATH) $(LDFLAGS) -o $(NAME)

clean		:
	$(RM) *~
	$(RM) *.o

fclean		: clean
	$(RM) $(NAME)

re		: fclean all
