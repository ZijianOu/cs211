Project6: proj5Base.o island.o
	g++ -o Project6 proj5Base.o island.o

proj5Base.o: proj5Base.cpp island.h
	g++ -c -g proj5Base.cpp

island.o: island.cpp island.h
	g++ -c -g island.cpp

clean:
	rm island.o proj5Base.o Project6