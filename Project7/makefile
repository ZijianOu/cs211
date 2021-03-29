Project7: proj7Base.o stack.o
	g++ -o Project7 proj7Base.o stack.o

proj5Base.o: proj7Base.cpp stack.h
	g++ -c proj7Base.cpp

stack.o: stack.cpp stack.h
	g++ -c stack.cpp

clean:
	rm stack.o proj7Base.o Project7