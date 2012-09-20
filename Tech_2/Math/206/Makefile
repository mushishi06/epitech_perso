##
## Makefile for 206 in /home/belia-_r/afs/Math/206
## 
## Made by belia-_r
## Login   <belia-_r@epitech.net>
## 
## Started on  Sun Apr 22 20:46:27 2012 belia-_r
## Last update Sun Apr 29 12:12:33 2012 belia-_r
##

NAME 	= 206observ
SRCS	= main.c 	\
	  open_path.c	\
	  xmalloc.c	\
	  xfclose.c

OPTI	= -O2

OBJOPT  = $(OPTI) -W -Wall
CFLAGS  = $(OBJOPT)
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
