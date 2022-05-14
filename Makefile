SOURCE:=src
TARGET:=bin
GENS:=$(SOURCE)/generators
OBJECTS:=$(SOURCE)/objects
FLAGS:=
all: main gen
main: main objects.o
gen: gen

objects.o: gen.cpp objects.hpp
	g++ -c $(OBJECTS)/gen/gen.cpp 

main: $(TARGET) data $(SOURCE)/main.cpp
	g++ $(SOURCE)/main.cpp -o $(TARGET)/main.exe $(FLAGS)

gen: $(TARGET) data $(GENS)/gen.cpp
	g++ $(GENS)/gen.cpp -o $(TARGET)/gen.exe $(FLAGS)


bin:
	if not exist bin\ md bin\

data:
	if not exist data\ md data\ 
	if not exist data\input\ md data\input\ 

clear:
	del /S *.exe