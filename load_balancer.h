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

    Load_Balancer(Req_Queue queue, Web_Server server);
    void allocate_requests();
};

Load_Balancer::Load_Balancer(Req_Queue queue, Web_Server server){
    myqueue = queue;
    myserver = server;
}

void Load_Balancer::allocate_requests(){
    int indx = 0;
    for(int queue_req = 0; queue_req < myqueue.size; queue_req++){
        Request new_request = myqueue.pop();
        
        if(new_request.time > myqueue.max_time){
            myqueue.max_time = new_request.time;
        }
        indx = myserver.process_requests(new_request, myqueue.max_time, indx);
    }
}

#endif /* MY_CLASS_H */