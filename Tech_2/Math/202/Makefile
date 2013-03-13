##
## Makefile for 202invendus in /home/belia-_r/afs/epitech_perso/Tech_2/Math/202
## 
## Made by romain belia-bourgeois
## Login   <belia-_r@epitech.net>
## 
## Started on  Mon Mar  4 22:53:46 2013 romain belia-bourgeois
## Last update Wed Mar 13 16:47:48 2013 romain belia-bourgeois
##

NAME 	= 202invendus
SRCS	= main.c \
	check_params.c	\
	get_params.c	\
	print_results.c	\
	loi.c		\
	exit_error.c	\
	xmalloc.c	\
	darrondi.c	\

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
