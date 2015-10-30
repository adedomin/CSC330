CC=c++
CFLAGS=-Wall --std=c++98 -O
NAME=SortList
DEPS=KEY.H LIST.H RANDOM.H RECORD.H SORTLIST.H TIMER.H
OBJ=KEY.o MAIN.o RANDOM.o RECORD.o SORTLIST.o TIMER.o

all: $(OBJ) executable clean
	
%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

executable:
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) 

clean:
	rm $(OBJ)

remove:
	rm $(NAME)
