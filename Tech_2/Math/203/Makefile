##
## Makefile for 203 in /home/belia-_r/afs/epitech_perso/Tech_2/Math/203
## 
## Made by romain belia-bourgeois
## Login   <belia-_r@epitech.net>
## 
## Started on  Wed Mar 20 21:43:04 2013 romain belia-bourgeois
## Last update Fri Mar 22 00:00:27 2013 romain belia-bourgeois
##

NAME 	= 203hotline
SRCS	= main.c \
	check_params.c	\
	get_params.c	\
	print_results.c	\
	loi.c		\
	exit_error.c	\
	xmalloc.c	\
	darrondi.c	\
	fact.c		\

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
