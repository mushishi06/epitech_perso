##
## Makefile for bomber in /home/ha-tam_l/Desktop/projet/bomberman/map
## 
## Made by laurent ha-tam-dan
## Login   <ha-tam_l@epitech.net>
## 
## Started on  Tue May 22 20:02:03 2012 laurent ha-tam-dan
## Last update Wed May 23 11:56:42 2012 belia-_r
##

NAME	=	test_map

SRC =		Generate_map.cpp	\
		main_test_map.cpp	\
		save_map.cpp		\
		load_map.cpp


OBJ =		$(SRC:.cpp=.o)
CC =		/usr/bin/g++
INCLUDE =	-I./headers/
CPPFLAGS +=	$(INCLUDE)
RM =		rm -f
ECHO =		echo -e

$(NAME):	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ)
		@$(ECHO) '\033[0;32m> Compiled\033[0m'

clean:
		-@$(RM) $(OBJ)
		-@$(RM) *~
		-@$(RM) *#
		@$(ECHO) '\033[0;35m> Directory cleaned\033[0m'

all:		$(NAME)

fclean:		clean
		-@$(RM) $(NAME)
		@$(ECHO) '\033[0;35m> Remove executable\033[0m'

re:		fclean all

.PHONY:		all clean re
