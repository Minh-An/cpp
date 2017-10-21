OBJS = main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c++11
LFLAGS = -Wall $(DEBUG) -std=c++11

dijkstra: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o dijkstra

main.o: graph.h priority_queue.h shortest_path.h main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm *.o dijkstra

zip:
	zip dijkstra.zip graph.h graph.cpp graph_client.cpp
