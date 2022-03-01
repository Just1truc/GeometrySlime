##
## EPITECH PROJECT, 2021
## my_runner
## File description:
##  program where the player have to avoid obstacle
##

SRC	=	$(wildcard sources/*.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include/

LFLAGS	=	-L/usr/local/lib -lcsfml-window \
		-lcsfml-graphics -lcsfml-system -lcsfml-audio

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all
