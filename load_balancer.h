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
    for(int clock_cycle = 0; clock_cycle < time_to_run; clock_cycle++){
        myserver.process_requests();
        if(!myqueue.empty()){
            Request new_request = myqueue.pop();
            cout<<"At clock cycle "<<clock_cycle;
            myserver.take_in_Request(new_request);
        }else{
            /*should I create a new queue and continue to process that?*/
            cout<<"All requests processed."<<endl;
            break;
        }

    }
}


#endif /* MY_CLASS_H */