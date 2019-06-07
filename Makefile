##
## EPITECH PROJECT, 2019
## mychap Makefile
## File description:
## made by Martin Vantalon
##

NAME= client

CC= gcc

CFLAG= -W -Wall -Wextra -I./include

LDFLAGS= -lssl -lcrypto

SRC=	srcs/parse.c\
	srcs/my_headers.c\
	srcs/my_sockets.c\
	srcs/my_authentification.c\
	srcs/main.c

OBJ=    $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
