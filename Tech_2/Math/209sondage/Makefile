##
## Makefile for 209sondage in /home/belia-_r/afs/epitech_perso/Tech_2/Math/209sondage
## 
## Made by romain belia-bourgeois
## Login   <belia-_r@epitech.net>
## 
## Started on  Sun Jun 16 00:36:22 2013 romain belia-bourgeois
## Last update Sun Jun 16 11:24:22 2013 romain belia-bourgeois
##

NAME 	= 209sondage

SRCS	= main.c	\

OPTI	= -O3 -os -g3

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
