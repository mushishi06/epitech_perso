##
## Makefile for 201yams in /home/belia-_r/afs/epitech_perso/Tech_2/Math/201
## 
## Made by romain belia-bourgeois
## Login   <belia-_r@epitech.net>
## 
## Started on  Thu Feb 28 18:55:54 2013 romain belia-bourgeois
## Last update Sun Mar  3 18:23:28 2013 romain belia-bourgeois
##

NAME 	= 201yams
SRCS	= main.c \
	yams.c		\
	suite.c		\
	full.c		\
	carre.c		\
	brelan.c	\
	paire.c		\
	check_lancer.c	\

OPTI	= -O2

IPATH   = -I./includes -I./src/proc
OBJOPT  = $(OPTI) -W -Wall
CFLAGS  = $(OBJOPT) $(IPATH)
CXXFLAGS= $(CFLAGS)

LPATH   = -L. -lm

RM 	= /bin/rm -f

CC 	= gcc

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
