##
## Makefile for 208chevillettes in /home/belia-_r/afs/epitech_perso/Tech_2/Math/208chevillettes
## 
## Made by romain belia-bourgeois
## Login   <belia-_r@epitech.net>
## 
## Started on  Wed Jun  5 14:15:56 2013 romain belia-bourgeois
## Last update Sat Jun  8 20:23:40 2013 romain belia-bourgeois
##

NAME 	= 208chevillettes

SRCS	= main.c	\
	donnes_x2.c	\
	fonc.c		\

OPTI	= -O3 -os

IPATH   = -I./include -I./src/proc
OBJOPT  = $(OPTI) -W -Wall -Werror -Wextra -ansi -pedantic
CFLAGS  = $(OBJOPT) $(IPATH)
CXXFLAGS= $(CFLAGS)

LPATH   = -L. -lm -lgmpxx -lgmp

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
