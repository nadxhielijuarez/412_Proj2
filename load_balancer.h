#include <iostream>
#ifndef LOAD_BALANCER_H // include guard
#define LOAD_BALANCER_H
#include "web_server.h"
#include "request.h"
#include "req_queue.h"

/*
where the queue is used. 

*/
class Load_Balancer{
    Req_Queue myqueue;
    Web_Server myserver;
    int time_to_run;
    public:
    Load_Balancer(Req_Queue queue, Web_Server server, int time);
    void allocate_requests();
};

Load_Balancer::Load_Balancer(Req_Queue queue, Web_Server server, int time){
    myqueue = queue;
    myserver = server;
    time_to_run = time;
}

void Load_Balancer::allocate_requests(){
    int indx = 0;
    int queue_req = 0;
    while(queue_req < time_to_run){
        Request new_request = myqueue.pop();
        if(new_request.time > myqueue.max_time){
            myqueue.max_time = new_request.time;
        }
        indx = myserver.process_requests(new_request, myqueue.max_time, indx);
        
        queue_req++;
    }
}

#endif /* MY_CLASS_H */