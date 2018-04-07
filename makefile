#This is the Makefile for Lab 10
#Author: Calista Wong 

output: gamePlay.o OTMain.o Person.o Space.o Missouri.o Wyoming.o Idaho.o Nebraska.o Nevada.o
	g++  gamePlay.o OTMain.o Person.o Space.o Missouri.o Wyoming.o Nebraska.o Idaho.o Nevada.o -o output

gamePlay.o: gamePlay.cpp gamePlay.hpp
	g++ -c gamePlay.cpp
OTMain.o: OTMain.cpp
	g++ -c OTMain.cpp
Person.o: Person.cpp Person.hpp
	g++ -c Person.cpp
Space.o: Space.cpp Space.hpp
	g++ -c Space.cpp
Missouri.o: Missouri.cpp Missouri.hpp
	g++ -c Missouri.cpp
Idaho.o: Idaho.cpp Idaho.hpp
	g++ -c Idaho.cpp
Wyoming.o: Wyoming.cpp Wyoming.hpp
	g++ -c Wyoming.cpp
Nebraska.o: Nebraska.cpp Nebraska.hpp
	g++ -c Nebraska.cpp
Nevada.o: Nevada.cpp Nevada.hpp
	g++ -c Nevada.cpp

clean:
	rm *.o output




	
