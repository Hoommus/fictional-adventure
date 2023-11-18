# Makefile for calculator

NAME = calc
CC = gcc

INCLUDE = $(LIBCALC_DIR)/calc.h
OBJ = main.o

LIBCALC=libcalc.a
LIBCALC_DIR=./libcalc/

LIBCONVERT_DIR=./libconvert/

FLAGS = -Wall -Wextra -L$(LIBCALC_DIR) -I$(LIBCALC_DIR) -I$(LIBCONVERT_DIR) -lcalc

all: libconvert $(LIBCALC) $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -lcalc -lm -lconvert

$(LIBCALC):
	make -C $(LIBCALC_DIR)

libconvert:
	make -C $(LIBCONVERT_DIR) install

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -o $@ -c $< 

clean:
	rm -f $(OBJ) $(NAME)
	make -C $(LIBCALC_DIR) clean
	make -C $(LIBCONVERT_DIR) clean

.PHONY = all clean
