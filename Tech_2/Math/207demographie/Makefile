##
## Makefile for 207demographie in /home/belia-_r/afs/epitech_perso/Tech_2/Math/207demographie
## 
## Made by romain belia-bourgeois
## Login   <belia-_r@epitech.net>
## 
## Started on  Sat Jun  1 18:01:13 2013 romain belia-bourgeois
## Last update Wed Jun  5 10:45:19 2013 romain belia-bourgeois
##

NAME 	= 207demographie

SRCS	= xmalloc.c	\
	fonctions.c	\
	xfclose.c	\
	207demographie_donnees.c \
	main.c		\
	sdl/fleche.c	\
	sdl/axes.c	\
	sdl/fonctions.c	\

OPTI	= -O3

IPATH   = -I./include -I./src/proc
OBJOPT  = #$(OPTI) -W -Wall
CFLAGS  = $(OBJOPT) $(IPATH) -g3
CXXFLAGS= $(CFLAGS)

LPATH   = -L. -lm `sdl-config --cflags --libs` -lSDL_gfx

RM 	= /bin/rm -f

CC 	= gcc #-m32

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
