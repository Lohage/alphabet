.PHONY: all test clean install uninstall

all: ./bin

./bin: ./build/src/main.o ./build/src/functions.o
	gcc -Wall ./build/src/main.o ./build/src/functions.o -o ./bin/alphabet

./build/src/main.o: ./src/main.c
	gcc -Wall -c ./src/main.c -o ./build/src/main.o

./build/src/functions.o: ./src/functions.c
	gcc -Wall -c ./src/functions.c -o ./build/src/functions.o

test: bin/alphabet_test

bin/alphabet_test: build/test/main.o build/test/functions.o
	gcc -Wall  build/test/main.o build/test/functions.o -o bin/alphabet_test

build/test/main.o: test/main.c
	gcc -Wall -c -I thirdparty -I src test/main.c -o build/test/main.o

build/test/functions.o: src/functions.c src/functions.h
	gcc -Wall -c -I thirdparty -I src src/functions.c -o build/test/functions.o

clean:
	rm ./bin/alphabet ./build/src/*.o
	rm ./bin/alphabet ./build/src/*.o

install: 
	sudo cp ./bin/alphabet /usr/local/bin/alphabet

uninstall:
	sudo rm -f /usr/local/bin/alphabet