# -*- Makefile -*- 

./exe/global.exe : ./objs/main.o ./objs/prioriter.o ./objs/function.o ./objs/fcfs.o ./objs/spf.o
	gcc ./objs/main.o  ./objs/prioriter.o ./objs/function.o ./objs/fcfs.o ./objs/spf.o -o ./exe/global.exe 

./objs/main.o : ./src/main.c 
	gcc -c ./src/main.c -o ./objs/main.o 
./objs/prioriter.o: ./src/prioriter.c
	gcc -c ./src/prioriter.c -o ./objs/prioriter.o
./objs/function.o: ./src/function.c  
	gcc -c ./src/function.c -o ./objs/function.o
./objs/fcfs.o : ./src/fcfs.c 
	gcc -c ./src/fcfs.c -o ./objs/fcfs.o
./objs/spf.o : ./src/spf.c 
	gcc -c ./src/spf.c -o ./objs/spf.o


