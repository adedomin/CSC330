CC=c++
CFLAGS=-Wall --std=c++11 -O
NAME=SortList
DEPS=KEY.H LIST.H RANDOM.H RECORD.H SORTLIST.H TIMER.H
OBJ=KEY.o RANDOM.o RECORD.o TIMER.o MAIN.o

all: $(OBJ) executable clean
	
%.o: %.CPP $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

executable:
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) 

clean:
	rm $(OBJ)

remove:
	rm $(NAME)
