all: build run clean
build: MainFile.c lab1z1v18.1.c lab1z1v18.2.c
	gcc -Wall -O0 -g3 -DDEBUG -pedantic-errors -std=c89 MainFile.c lab1z1v18.1.c lab1z1v18.2.c -o programm
	
run: programm.exe
	./programm.exe
	
clean: 
	rm -rf *.o programm