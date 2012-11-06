##
## Makefile for  in /home/jason/Tech2/ProgC++/Bomberman
## 
## Made by Jason Leo
## Login   <jason@epitech.net>
## 
## Started on  Wed May  2 15:19:01 2012 Jason Leo
## Last update Sun Jun  3 16:33:28 2012 jason leo
##

NAME		=		Bomberman

CXX		=		g++

RM		=		rm -rf

GDL		=		./libgdl_gl/

INCS		=		-I ./includes/

INCS_GDL	=		-I $(GDL)include/

SRCS_D		=		./sources/

SRCS		=		$(SRCS_D)main.cpp		\
				$(SRCS_D)Aintelligence.cpp	\
				$(SRCS_D)Background.cpp		\
				$(SRCS_D)Bomb.cpp		\
				$(SRCS_D)Bomber.cpp		\
				$(SRCS_D)Camera.cpp		\
				$(SRCS_D)Generate_map.cpp	\
				$(SRCS_D)Load_map.cpp		\
				$(SRCS_D)Monster.cpp		\
				$(SRCS_D)MyGame.cpp		\
				$(SRCS_D)MyText.cpp		\
				$(SRCS_D)Object.cpp		\
				$(SRCS_D)Player.cpp		\
				$(SRCS_D)MyMenu.cpp		\
				$(SRCS_D)MyBack.cpp		\
				$(SRCS_D)MyCursor.cpp		\
				$(SRCS_D)MultCursor.cpp		\
				$(SRCS_D)Timer.cpp		\
				$(SRCS_D)Save_map.cpp		\
				$(SRCS_D)SecondBomber.cpp	\
				$(SRCS_D)Vector3f.cpp

OBJS		=		$(SRCS:.cpp=.o)

CXXFLAGS	+=		-O3 -Os -freorder-blocks-and-partition -ftree-vect-loop-version
CXXFLAGS	+=		-falign-functions -falign-jumps -falign-loops -falign-labels
CXXFLAGS	+=		-ansi -pedantic
CXXFLAGS	+=		-W -Wall -Werror -Wextra

LIB_GDL		=		-L $(GDL)lib -Wl,--rpath=$(GDL)lib -lgdl_gl -lGL -lGLU -lfmodex

all		:		$(NAME)

$(NAME)		:		$(OBJS)
				$(CXX) -o $(NAME) $(OBJS) $(INCS) $(CXXFLAGS) $(INCS_GDL) $(LIB_GDL)
				@echo 'Compilation Bomberman : DONE'

clean		:
				@$(RM) $(OBJS) *~ *# $(SRCS_D)*~ $(SRCS_D)*#
				@echo 'Cleaning directory : DONE'

fclean		:		clean
				@$(RM) $(NAME)
				@echo 'Full Cleaning directory : DONE'

re		:		fclean all
				@echo 'Recompilation : Done'

.cpp.o		:
				$(CXX) $(INCS) $(CXXFLAGS) $(INCS_GDL) $(LIB_GDL) -c $< -o $(<:.cpp=.o)

.PHONY		:		all clean fclean re