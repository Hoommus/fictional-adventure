# Makefile for calculator

NAME = calc
CC = gcc


INCLUDE = $(LIBCALC_DIR)/calc.h
OBJ = main.o

LIBCALC=libcalc.a
LIBCALC_DIR=./libcalc/

FLAGS = -Wall -Wextra -L$(LIBCALC_DIR) -I$(LIBCALC_DIR) -lcalc

all: $(LIBCALC) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -lcalc -lm

$(LIBCALC):
	make -C $(LIBCALC_DIR)

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -o $@ -c $< 

clean:
	rm -f $(OBJ) $(NAME)
	make -C $(LIBCALC_DIR) clean

.PHONY = all clean
