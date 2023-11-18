
NAME=libcalc.a
OBJ=div.o fact.o prod.o sqrt.o subt.o sum.o

CC=gcc

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) -o $@ -c $< -lm

clean:
	rm -f $(NAME)
	rm -f $(OBJ)

