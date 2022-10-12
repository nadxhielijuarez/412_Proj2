OBJS	= main.o
SOURCE	= main.cpp
HEADER	= load_balancer.h req_queue.h request.h web_server.h
OUT	= LB
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 


clean:
	rm -f $(OBJS) $(OUT)
