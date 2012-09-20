##
## Makefile for 204 in /home/belia-_r/afs/Math/204
## 
## Made by belia-_r
## Login   <belia-_r@epitech.net>
## 
## Started on  Sun Apr 22 20:46:27 2012 belia-_r
## Last update Sun Apr 22 20:47:02 2012 belia-_r
##

NAME 	= 204param
SRCS	= main.c \
	others.c

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
