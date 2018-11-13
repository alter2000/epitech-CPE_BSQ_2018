##
## EPITECH PROJECT, 2018
## CPool_Day07_2018
## File description:
## standard makefile
##

NAME=calc
CFLAGS+= -Wall -I./include -L./lib/my -lmy
SRC=$(wildcard *.c)

all: $(NAME)

$(NAME): $(SRC) $(wildcard include/*.h)
	@$(MAKE) -C ./lib/my
	@gcc -o $(NAME) $(SRC) $(CFLAGS)

debug:
	@$(MAKE) -C ./lib/my debug
	clang -o $(NAME) $(SRC) $(CFLAGS) -g

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C ./lib/my clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C ./lib/my fclean

re: fclean $(NAME)

tests_run:
	gcc -o unit_tests $(shell find ./tests/ -name '*.c') $(filter-out main.c, $(SRC)) \
		--coverage -lcriterion $(CFLAGS)
	./unit_tests

.PHONY: all clean fclean re debug tests_run
