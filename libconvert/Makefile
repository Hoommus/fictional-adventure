
NAME=libconvert.so
OBJ=upper.o lower.o

CC=gcc

HEADER=convert.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -shared -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	rm -f $(NAME)
	rm -f $(OBJ)

install: $(NAME)
	cp $(NAME) /usr/lib/
	cp $(HEADER) /usr/include/
	ldconfig

