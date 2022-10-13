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
   // cout<<"server of size:" <<server.server_size<<endl;
    time_to_run = time;
}

void Load_Balancer::allocate_requests(){
    for(int clock_cycle = 0; clock_cycle < time_to_run; clock_cycle++){
        myserver.process_requests();
        Request myReq;
        //every 5 or 2 seconds enter a requests
        if(clock_cycle%5==0){
            myserver.take_in_request(myReq); 
        }else if( clock_cycle %2==0){
            myserver.take_in_request(myReq);
        }
        
    }
}


#endif /* MY_CLASS_H */