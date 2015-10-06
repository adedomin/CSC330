CC=c++
CFLAGS=-Wall --std=c++98 -O
NAME=ADTbag
DEPS=ADTbag.h
OBJ=main.o

all: $(OBJ) executable clean
	
%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

executable:
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) 

clean:
	rm $(OBJ)

remove:
	rm $(NAME)
