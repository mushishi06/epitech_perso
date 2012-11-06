##
## Makefile for Epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r
## 
## Made by belia-_r
## Login   <belia-_r@epitech.net>
## 
## Started on  Sat Mar  3 11:42:10 2012 belia-_r
## Last update Sun Mar  4 22:40:33 2012 belia-_r
##

NAME	= epikong_etape_3
CFLAG	= -W -Werror -Wall -lSDLmain -lSDL -lSDL_image -lSDL_ttf `sdl-config --cflags --libs`

SRCS	= parseur.c	\
	  main.c	\
          run.c		\
	  sdl_basics.c	\
	  draw_map.c	\
	  aff_info.c	\
	  checkEvents2.c	\
	  eventskong.c	\
	  eventskong2.c	\
	  move_mob.c	\
	  fall.c	\
	  others2.c	\
	  kongjump.c	\
	  kongjump2.c	\
	  menu.c	\
	  index.c	\
	  index_content.c	\

OBJS	= parseur.o	\
	  main.o	\
	  run.o		\
	  sdl_basics.o	\
	  draw_map.o	\
	  aff_info.o	\
	  eventskong.o	\
	  checkEvents2.o	\
	  eventskong2.o	\
	  move_mob.o	\
	  fall.o	\
	  others2.o	\
	  kongjump.o	\
	  kongjump2.o	\
	  menu.o	\
	  index.o	\
	  index_content.o	\

CC	= gcc

RM	= rm -rf

all: $(NAME)

$(NAME):
	@$(CC) -c $(SRCS) $(CFLAG)
	@$(CC) -o $(NAME) $(OBJS) $(CFLAG)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
