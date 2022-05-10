SOURCE:=src
TARGET:=bin
FLAGS:=
all: main

main: $(TARGET) data $(SOURCE)/main.cpp
	g++ $(SOURCE)/main.cpp -o $(TARGET)/main.exe $(FLAGS)

bin:
	if not exist bin \md bin\

data:
	if not exist data\ md data\

clear:
	del /S *.exe