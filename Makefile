##
## Makefile for Matchstick in /home/fox/epitech/B2/B2-C-Prog_Elem/CPE_2016_matchstick
## 
## Made by Fernand Matignon
## Login   <fernand.matignon@epitech.eu>
## 
## Started on  Wed Feb 22 22:32:03 2017 Fernand Matignon
## Last update Sun Feb 26 22:43:35 2017 Fernand Matignon
##

REPO = 		CPE_2016_matchstick

NAME =		matchstick

LIBNAME =	my

RM = 		rm -f

LIB =		-Llib -l$(LIBNAME)

CFLAGS = 	-Iinclude -Wall -Wextra

GCC =		gcc -o 

GCCLIB =	ar rc lib$(LIBNAME).a

TO_O =		$(SRC:.c=.o)

USER = 		@whoami

SRC = 		main.c	\
		other.c	\
		game.c	\
		game_ai.c

all: $(NAME)

$(NAME):$(TO_O)
	@$(GCC) $(NAME) $(CFLAGS) $(TO_O) $(LIB)

g3: $(TO_O)
	@$(GCC) $(NAME) -g3 $(CFLAGS) $(TO_O) $(LIB)

clean:
	@$(RM) *.o

fclean: clean
	@$(RM) *~
	@$(RM) $(NAME)

re: fclean all

push: fclean
	@git add --all
	@git commit -am "Push by Makefile"
	@git push

help:
	@echo "make : all          (edit for chose de default make)"
	@echo "       g3	   (gcc with -g3)"
	@echo "       clean        (rm all.o)"
	@echo "       fclean       (clean & rm NAME)"
	@echo "       re           (remake)"
	@echo "       create_repo  (create + clone REPO)"
	@echo "       push         (clean & push all)"
	@echo "       clock        (turn your term into clock)"
	@echo "       it_rain      (secret)"

clock:
	@watch -t -n 1 date

it_rain:
	@firefox -height 1080 -width 600 www.moneylovin.com

.PHONY: all $(NAME) convert_to_o clean fclean re push help clock it_rain
