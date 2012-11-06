##
## Makefile for Epikong in /home/belia-_r/afs/Rush/psu-rush1-2015-belia-_r
## 
## Made by belia-_r
## Login   <belia-_r@epitech.net>
## 
## Started on  Sat Mar  3 11:42:10 2012 belia-_r
## Last update Sat Mar  3 13:36:05 2012 belia-_r
##

NAME	= epikong_etape_1
CFLAG	=  -lSDLmain -lSDL -lSDL_image -lSDL_ttf `sdl-config --cflags --libs`

SRCS	= parseur.c	\
	  main.c	\
          run.c		\
	  sdl_basics.c	\
	  draw_map.c	\
	  aff_info.c

OBJS	= parseur.o	\
	  main.o	\
	  run.o		\
	  sdl_basics.o	\
	  draw_map.o	\
	  aff_info.o

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
