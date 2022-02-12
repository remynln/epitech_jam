##
## EPITECH PROJECT, 2022
## B-PDG-300-TLS-3-1-PDGD11-leo.maman [WSL: Ubuntu]
## File description:
## Makefile
##

SRC =	src/Game.cpp		\
		src/mini_games/schoolPriorities.cpp	\
		src/mini_games/SchoolPriorities.cpp	\
		main.cpp


CPPFLAGS = -std=c++2a -Wall -Wextra 

HEADERS = -L headers/

NAME = MyGKrellm

all: $(NAME)

$(NAME):
	g++ -o $(NAME) $(SRC) $(HEADERS) $(CFLAGS) -lncurses -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
	rm -f ../$(NAME)

re: fclean all