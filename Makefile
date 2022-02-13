##
## EPITECH PROJECT, 2022
## Epitech JAM
## File description:
## Makefile
##

SRC =	src/Game.cpp						\
		src/mini_games/schoolPriorities.cpp	\
		src/mini_games/SchoolPriorities.cpp \
		src/mini_games/defeatKFC.cpp \
		src/mini_games/DefeatKFC.cpp \
		src/mini_games/dodgeBottle.cpp	\
		src/mini_games/DodgeBottle.cpp	\
		src/mini_games/beetsaber.cpp 		\
		src/mini_games/CubeComming.cpp		\
		src/mini_games/psykologu.cpp		\
<<<<<<< HEAD
<<<<<<< HEAD
=======
		src/mini_games/marcolito.cpp		\
>>>>>>> 4bc22dc7650a2fb49b370191e17d78a5298d4caa
		src/Scenario.cpp					\
		src/DecisionWall.cpp				\
		src/mini_games/cake.cpp				\
		src/achievement.cpp 				\
<<<<<<< HEAD
=======
		src/mini_games/marcolito.cpp		\
		src/mini_games/space.cpp			\
		src/Scenario.cpp					\
		src/DecisionWall.cpp				\
		src/mini_games/cake.cpp				\
		src/achievement.cpp 				\
		src/ScriptChoice.cpp				\
>>>>>>> space_mini_game
=======
		src/ScriptChoice.cpp				\
>>>>>>> 4bc22dc7650a2fb49b370191e17d78a5298d4caa
		main.cpp

OBJ =	$(SRC:.cpp=.o)

<<<<<<< HEAD
<<<<<<< HEAD
CPPFLAGS	= -I./headers/ -std=c++2a -W -J4 -Wall -Werror -Wextra
=======
CPPFLAGS	= -I./headers/ -std=c++2a -W -J4 -Wall -Wextra -Werror -Wpedantic
>>>>>>> space_mini_game
=======
CPPFLAGS	= -I./headers/ -std=c++2a -W -J4 -Wall -Wextra -Werror -Wpedantic
>>>>>>> 4bc22dc7650a2fb49b370191e17d78a5298d4caa

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