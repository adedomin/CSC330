CC=c++
CFLAGS=-Wall --std=c++98 -O
NAME=CircularArray
DEPS=Queue.h
OBJ=main.o Queue.o

all: $(OBJ) executable clean
	
%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

executable:
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) 

clean:
	rm $(OBJ)

remove:
	rm $(NAME)
