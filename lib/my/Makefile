##
## Makefile for Makefile in /home/lecuye_j/rendu/Piscine_C_J11/lib/my
## 
## Made by Johan Lecuyer
## Login   <lecuye_j@epitech.net>
## 
## Started on  Mon Oct 20 09:26:23 2014 Johan Lecuyer
## Last update Sun Oct  4 11:49:40 2015 Johan Lecuyer
##

SRC	=	my_find_prime_sup.c	\
		my_getnbr.c		\
		my_isneg.c		\
		my_is_prime.c		\
		my_power_rec.c		\
		my_putchar.c		\
		my_puterror.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_revstr.c		\
		my_sort_int_tab.c	\
		my_square_root.c	\
		my_strcapitalize.c	\
		my_strcat.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strdup.c		\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c		\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlcat.c		\
		my_strlen.c		\
		my_strlowcase.c		\
		my_strncat.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_strstr.c		\
		my_strupcase.c		\
		my_swap.c		\
		my_show_wordtab.c	\
		my_str_to_wordtab.c	\
		get_next_line.c		\


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

HEAD	=	my.h

CHEML	=	./../

CHEMI	=	./../../include/

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	mv $(NAME) $(CHEML)
	cp $(HEAD) $(CHEMI)

clean: 
	rm -f $(CHEML)$(NAME)
	rm -f $(CHEMI)$(HEAD)

fclean:	clean
	rm -f $(OBJ)

re: fclean all
