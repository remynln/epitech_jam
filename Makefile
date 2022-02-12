##
## EPITECH PROJECT, 2022
## Epitech JAM
## File description:
## Makefile
##

SRC =	src/Game.cpp						\
		src/mini_games/schoolPriorities.cpp	\
		src/mini_games/SchoolPriorities.cpp \
		src/mini_games/beetsaber.cpp 		\
		src/Scenario.cpp					\
		src/init_scenario.cpp				\
		main.cpp

OBJ =	$(SRC:.cpp=.o)

CPPFLAGS	= -I./headers/

CFLAGS	= -std=c++2a -W -J4 -Wall -Werror -Wextra

CSFMLFLAGS	= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

NAME	=	weNeedToFindAName

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CSFMLFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -f ../$(NAME)

re: fclean all