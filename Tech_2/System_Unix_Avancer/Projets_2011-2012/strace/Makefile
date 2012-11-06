NAME	=	test
ASM	=	nasm
LD	=	gcc
SRC	=	main.S
OBJ	=	$(SRC:.S=.o)
LDFLAGS	=	-fno-builtin
CFLAGS	=	-f elf64

.S.o	:
	${ASM} ${CFLAGS} $< -o $@

${NAME}	:	${OBJ}
	 ${LD} ${OBJ} -o ${NAME} ${LDFLAGS}

all	:	${NAME}

clean	:
	rm -fr ${OBJ}

fclean	:	clean
	rm -fr ${NAME}