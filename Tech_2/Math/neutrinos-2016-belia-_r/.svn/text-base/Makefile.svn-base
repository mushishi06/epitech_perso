##
## Makefile for 206neutrinos in /home/belia-_r/afs/epitech_perso/Tech_2/Math/206neutrinos
## 
## Made by romain belia-bourgeois
## Login   <belia-_r@epitech.net>
## 
## Started on  Thu May 16 17:50:52 2013 romain belia-bourgeois
## Last update Sat May 18 00:09:55 2013 romain belia-bourgeois
##

NAME 	= 206neutrinos

SRCS	= main.c	\
	ec_type.c	\
	moy_arith.c	\
	moy_harmo.c	\
	moy_quadra.c	\

OPTI	= -O3 -os

IPATH   = -I./include -I./src/proc
OBJOPT  = $(OPTI) -W -Wall -Werror -Wextra -ansi -pedantic
CFLAGS  = $(OBJOPT) $(IPATH)
CXXFLAGS= $(CFLAGS)

LPATH   = -L. -lm

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
