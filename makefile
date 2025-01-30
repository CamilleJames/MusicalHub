.PHONY:all clean
all:dowork
	echo "all is done"
dowork:main.o musical.o
	g++ main.o musical.o -o dowork

dowork:main.o musical.o
	g++ main.o musical.o -o dowork

main.o:main.cpp
	g++ -c main.cpp
musical.o:musical.cpp
	g++ -c musical.cpp

clean :
	rm -f *.o dowork