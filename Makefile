all: hello

hello:  gcdriver.o gc.o su.o 
	g++ gcdriver.o  gc.o su.o -o hello

gcdriver.o: gcdriver.cpp
	g++ -c gcdriver.cpp 

gc.o: GraphConstruction.cpp
	g++ -c GraphConstruction.cpp -o gc.o

su.o: StringUtilities.cpp
	g++ -c StringUtilities.cpp -o su.o

clean:
	rm -rf *o hello
