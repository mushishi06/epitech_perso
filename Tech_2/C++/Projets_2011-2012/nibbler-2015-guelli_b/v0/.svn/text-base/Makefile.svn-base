##
## Makefile for  in /home/moreno_i//afs/renduLocal/projets/nibbler
## 
## Made by igor morenosemedo
## Login   <moreno_i@epitech.net>
## 
## Started on  Fri Mar 16 00:34:06 2012 igor morenosemedo
## Last update Sun Mar 18 02:19:23 2012 igor morenosemedo
##

NAME 		= 	nibbler

SRC 		= 	Snake.cpp		\
			DLLoader.cpp		\
			Arguments.cpp		\
			main.cpp

OBJ 		= 	$(SRC:.cpp=.o)

CC 		=	g++

CPPFLAGS 	= 	-W -Wall -Wextra -Werror -ansi

LDFLAGS		= 	-ldl

LIB1 		=	SFML

LIB2 		=	QT

LIB3		=	ncurses

RM		=	rm -f

MAKE		=	make -sC

all		:	$(NAME)

$(NAME) 	:	$(OBJ)
			@echo -e '\033[34m -$(LIB1)-\033[0m'
			@$(MAKE) lib_SFML
			@$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)
			@echo -e '\033[35m -$(LIB2)-\033[0m'
			@$(MAKE) lib_QT
			@$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)
			@echo -e '\033[32m -$(LIB3)-\033[0m'
			@$(MAKE) lib_ncurses
			@$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)
			@echo ''

clean 		:
			@echo -e '\033[34m $(LIB1) clean -\033[0m'
			@$(MAKE) lib_SFML clean
			@echo -e '\033[35m $(LIB2) clean -\033[0m'
			@$(MAKE) lib_QT clean
			@echo -e '\033[32m $(LIB3) clean -\033[0m'
			@$(MAKE) lib_ncurses clean
			@$(RM) *.o *~
			@echo ''

fclean 		: 	clean
			@echo -e '\033[34m $(LIB1) fclean -\033[0m'
			@$(MAKE) lib_SFML fclean
			@echo -e '\033[35m $(LIB2) fclean -\033[0m'
			@$(MAKE) lib_QT clean
			@echo -e '\033[32m $(LIB3) fclean -\033[0m'
			@$(MAKE) lib_ncurses fclean
			@$(RM) $(NAME)
			@echo ''

re 		:	fclean all
