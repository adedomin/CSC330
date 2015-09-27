CC=c++
CFLAGS=-Wall --std=c++11
NAME=ADTbag
DEPS=ADTbag.h
OBJ=ADTbag.o main.o

all: $(OBJ) executable
	
%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

executable:
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) 
	make clean

clean:
	rm $(OBJ)

remove:
	rm $(NAME)
