all: clean build run

build:
	gcc -I ./include/ -o ./lib/Dosya.o -c ./src/Dosya.c
	gcc -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.c
	gcc -I ./include/ -o ./lib/Oyun.o -c ./src/Oyun.c
	gcc -I ./include/ -o ./lib/Yardimci.o -c ./src/Yardimci.c
	gcc -I ./include/ -o ./bin/Test ./lib/Dosya.o ./lib/Kisi.o ./lib/Oyun.o ./lib/Yardimci.o ./src/Test.c

run:
	./bin/Test

debug: CXXFLAGS += -DDEBUG -g
debug: CCFLAGS += -DDEBUG -g
debug: build

clean:
	del .\bin\Test.exe
	del .\lib\Dosya.o
	del .\lib\Kisi.o
	del .\lib\Oyun.o
	del .\lib\Yardimci.o