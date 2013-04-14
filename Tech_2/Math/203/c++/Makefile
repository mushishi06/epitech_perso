##
## Makefile for 203hotline in /home/belia-_r/afs/epitech_perso/Tech_2/Math/203/c++
## 
## Made by romain belia-bourgeois
## Login   <belia-_r@epitech.net>
## 
## Started on  Sat Mar 23 17:17:57 2013 romain belia-bourgeois
## Last update Sun Mar 31 18:27:16 2013 romain belia-bourgeois
##

NAME	=	203hotline

DIRHEAD	=	./headers/

DIRSRC	=	./sources/

SRC	=	$(DIRSRC)main.cpp\

INCLUDE	=	-I$(DIRHEAD)

CFLAGS	+=	-lgmpxx -lgmp #-W -Wall -Wextra -Werror -pedantic -ansi

all	:
		g++ $(SRC) -o $(NAME) $(CFLAGS) $(INCLUDE)

clean	:
		rm -f *.o *~ \#*\#

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	fclean clean all re