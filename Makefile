OBJS	= main.o
SOURCE	= main.cpp
HEADER	= req_queue.h request.h load_balancer.h web_server.h
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