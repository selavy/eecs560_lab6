CPP = g++
CFLAGS = -Wall -Werror -pedantic
ARRAY = -DARRAY
AVLTREE = -DAVLTREE
OBJS = AVLTree.o Array.o main.o
COUNT_OBJS = cAVLTree.o cArray.o cmain.o
MATH = -lm
COUNT = -DCOUNT

2208496_lab6: $(OBJS)
	$(CPP) -o 2208496_lab6 $(CFLAGS) $(OBJS)
count_avl: $(COUNT_OBJS)
	$(CPP) -o count_avl $(CFLAGS) $(COUNT_OBJS) $(AVLTREE)
count_array: $(COUNT_OBJS)
	$(CPP) -o count_array $(CFLAGS) $(COUNT_OBJS)
cmain.o: main.cpp
	$(CPP) $(CFLAGS) -c main.cpp -o cmain.o $(ARRAY) $(COUNT)
main.o: main.cpp
	$(CPP) $(CFLAGS) -c main.cpp $(ARRAY)
cAVLTree.o: AVLTree.cpp AVLTree.hpp
	$(CPP) $(CFLAGS) -c AVLTree.cpp $(MATH) $(COUNT) -o cAVLTree.o
AVLTree.o: AVLTree.cpp AVLTree.hpp
	$(CPP) $(CFLAGS) -c AVLTree.cpp $(MATH)
cArray.o: Array.hpp Array.cpp
	$(CPP) $(CFLAGS) -c Array.cpp $(MATH) $(COUNT) -o cArray.o
Array.o: Array.cpp Array.hpp
	$(CPP) $(CFLAGS) -c Array.cpp $(MATH)
clean:
	rm -rf *.o 2208496_lab6 count_*
