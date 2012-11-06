##
## Makefile for nibbler in /home/guelli_b//Epitech/tek2/B4/C++/Nibbler/nibbler/lnibbler
## 
## Made by badrane guellim
## Login   <guelli_b@epitech.net>
## 
## Started on  Wed Mar 14 16:34:09 2012 badrane guellim
## Last update Sat Mar 17 15:45:11 2012 badrane guellim
##

NAME		=	lib_nibbler_ncurses.so

CMP		=	g++

RM		=	rm -f

CFLAGS		+=	-W -Wall -Wextra -Werror -pedantic -ansi -fPIC

LDFLAGS		+=	-lncurses

SRC_DIR		=	src/

OBJ_DIR		=	obj/

INC_DIR		=	include/

SRC		=	$(SRC_DIR)Ncurses.cpp

OBJ		=	$(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

all		:	$(NAME)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.cpp
			$(CMP) $(CFLAGS) $(LDFLAGS) -c -I$(INC_DIR) -o $@ $<


$(NAME)		:	$(OBJ)
			$(CMP) -shared $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ)

clean		:
			$(RM)		\#*\#
			$(RM)		*~
			$(RM)		$(INC_DIR)*~
			$(RM)		$(INC_DIR)\#*\#
			$(RM)		$(SRC_DIR)*~
			$(RM)		$(SRC_DIR)\#*\#

fclean		:	clean
			$(RM)		$(NAME)

re		:	fclean all

.PHONY		:	all clean re