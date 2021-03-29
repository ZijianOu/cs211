Project4: main.o linkedlistfunctions.o do-functions.o
	gcc -o Project4 main.o linkedlistfunctions.o do-functions.o

main.o: main.c allfunctions.h
	gcc -c main.c

linkedlistfunctions.o: linkedlistfunctions.c allfunctions.h
	gcc -c linkedlistfunctions.c

functionsuser.o: do-functions.c allfunctions.h
	gcc -c do-functions.c

clean:
	rm linkedlistfunctions.o do-functions.o main.o Project4