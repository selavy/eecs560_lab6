CPP = g++
CFLAGS = -Wall -Werror -pedantic
ARRAY = -DARRAY
AVLTREE = -DAVLTREE
OBJS = AVLTree.o Array.o main.o
MATH = -lm

2208496_lab6: $(OBJS)
	$(CPP) -o 2208496_lab6 $(CFLAGS) $(OBJS)
main.o: main.cpp
	$(CPP) $(CFLAGS) -c main.cpp
AVLTree.o: AVLTree.cpp AVLTree.hpp
	$(CPP) $(CFLAGS) -c AVLTree.cpp
Array.o: Array.cpp Array.hpp
	$(CPP) $(CFLAGS) -c Array.cpp $(MATH)
clean:
	rm -rf *.o 2208496_lab6
