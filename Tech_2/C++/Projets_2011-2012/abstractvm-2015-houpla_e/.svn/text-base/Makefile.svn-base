##
## Makefile for  in /home/emelyne/rendu/abstractVM
## 
## Made by Emelyne
## Login   <emelyne@epitech.net>
## 
## Started on  Fri Feb  3 16:05:18 2012 Emelyne
## Last update Wed Feb 15 16:59:13 2012 Emelyne
##

NAME	=	avm

DIRHEAD	=	./headers/

DIRSRC	=	./sources/

SRC	=	$(DIRSRC)main.cpp\
		$(DIRSRC)read.cpp\
		$(DIRSRC)parsFile.cpp\
		$(DIRSRC)Line.cpp\
		$(DIRSRC)Comm.cpp\
		$(DIRSRC)AOperand.cpp\
		$(DIRSRC)OperandInt8.cpp\
		$(DIRSRC)OperandInt16.cpp\
		$(DIRSRC)OperandInt32.cpp\
		$(DIRSRC)OperandFloat.cpp\
		$(DIRSRC)OperandDouble.cpp\
		$(DIRSRC)Memory.cpp\
		$(DIRSRC)Error.cpp

INCLUDE	=	-I$(DIRHEAD)

CFLAGS	+=	-W -Wall -Wextra -Werror -pedantic -ansi

all	:
		g++ $(SRC) -o $(NAME) $(CFLAGS) $(INCLUDE)

clean	:
		rm -f *.o *~ \#*\#

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	fclean clean all re