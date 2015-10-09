CC=c++
CFLAGS=-Wall --std=c++98 -O
NAME=LinkedBag
DEPS=LinkedBag.h Node.h
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
