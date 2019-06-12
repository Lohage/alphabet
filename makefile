.PHONY: all clean install uninstall

all: ./bin

./bin: ./build/src/main.o ./build/src/functions.o
	gcc -Wall ./build/src/main.o ./build/src/functions.o -o ./bin/alphabet

./build/src/main.o: ./src/main.c
	gcc -Wall -c ./src/main.c -o ./build/src/main.o

./build/src/functions.o: ./src/functions.c
	gcc -Wall -c ./src/functions.c -o ./build/src/functions.o

clean:
	rm ./bin/alphabet ./build/src/*.o

install: 
	sudo cp ./bin/alphabet /usr/local/bin/alphabet

uninstall:
	sudo rm -f /usr/local/bin/alphabet
