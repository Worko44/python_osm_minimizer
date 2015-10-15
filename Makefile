
CHEM	=	./src/

SRC	=	$(CHEM)recup_info.c	\
		$(CHEM)read_conf.c		\
		$(CHEM)recup_type.c		\
		$(CHEM)opp_tab.c		\

MAIN	=	$(CHEM)main.c		\

MAIN2	=	$(CHEM)main_filter.c		\

OBJ	=	$(SRC:.c=.o)

OBJ1	=	$(MAIN:.c=.o)

OBJ2	=	$(MAIN2:.c=.o)



CFLAGS	=	-I ./include/ -Wextra -Werror -Wall -std=gnu99

LIB	=	-lmy -L./lib/

NAME	=	osmMinimizer1

NAME2	=	osmMinimizer

CC	=	gcc

COMPLIB =	complib

all	: 	$(COMPLIB) $(NAME2) 

$(NAME)	:	 $(OBJ) $(OBJ1)
		$(CC) -o $(NAME) $(OBJ) $(OBJ1) $(LIB)

$(NAME2)	:	 $(OBJ) $(OBJ2)
		$(CC) -o $(NAME2) $(OBJ) $(OBJ2) $(LIB)

$(COMPLIB):	
		cd ./lib/my/ ; make re

clean	:
		rm -f $(NAME)
		rm -f $(NAME2)

fclean	:	clean
		rm -f $(OBJ)
		rm -f $(OBJ1)
		rm -f $(OBJ2)

re	:	fclean all
