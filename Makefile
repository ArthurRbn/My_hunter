##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	src/my_hunter.c	\
		src/hunter_destroy.c	\
		src/hunter_events.c	\
		src/hunter_help.c	\
		src/hunter_init.c\
		src/hunter_loops.c	\
		src/sprites_manage.c\
		src/nbr_to_str.c\
		src/my_putchar.c\
		src/my_putstr.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

LDFLAGS	=	-lcsfml-window -lcsfml-graphics -lcsfml-system

CFLAGS	+=	-Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc  $(LDFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all