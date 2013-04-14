##
## Makefile for 204 in /home/belia-_r/afs/Math/204
## 
## Made by belia-_r
## Login   <belia-_r@epitech.net>
## 
## Started on  Sun Apr 22 20:46:27 2012 belia-_r
## Last update Fri Apr 12 21:39:01 2013 romain belia-bourgeois
##

NAME 	= 204canard

SRCS	= xmalloc.c	\
	main.c		\
	sdl/fleche.c	\
	sdl/axes.c	\
	sdl/fonctions.c	\
#	test.c		\

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
