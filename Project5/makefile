Project5: proj5Base.o island.o
	g++ -o Project5 proj5Base.o island.o

proj5Base.o: proj5Base.cpp island.h
	g++ -c proj5Base.cpp

island.o: island.cpp island.h
	g++ -c island.cpp

clean:
	rm island.o proj5Base.o Project5