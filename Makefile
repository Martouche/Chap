##
## EPITECH PROJECT, 2019
## my ftp Makefile
## File description:
## made by Martin Vantalon
##

NAME= client

CC= gcc

CFLAG= -W -Wall -Wextra -I./include -L/usr/lib -lssl -lcrypto

SRC=	srcs/parse.c\
	srcs/main.c

OBJ=    $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
