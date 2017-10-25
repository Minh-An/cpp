OBJS = main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c++11
LFLAGS = -Wall $(DEBUG) -std=c++11

prim: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o prim

main.o: graph.h priority_queue.h mst.h main.cpp 
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm *.o prim

zip:
	zip mst.zip graph.h priority_queue.h mst.h main.cpp small.graph large.graph test.graph README.pdf makefile
