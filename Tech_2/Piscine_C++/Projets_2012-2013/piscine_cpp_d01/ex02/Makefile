##
## Makefile for ex02d01 in /home/belia-_r/afs/epitech_perso/Tech_2/Piscine_C++/Projets_2012-2013/piscine_cpp_d01/ex02
## 
## Made by belia-_r
## Login   <belia-_r@epitech.net>
## 
## Started on  Tue Dec  4 23:46:34 2012 belia-_r
## Last update Tue Dec  4 23:52:56 2012 belia-_r
##

NAME	= 
CFLAG	=  -Wextra -Werror -Wall -std=gnu99

SRCS	= menger.c	\
	  main.c	\

OBJS	= menger.o	\
	  main.o	\

CC	= gcc

RM	= rm -rf

all: $(NAME)

$(NAME):
	$(CC) -c $(SRCS) $(CFLAG)
	$(CC) -o $(NAME) $(OBJS) $(CFLAG)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
