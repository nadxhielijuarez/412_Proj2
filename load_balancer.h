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
    cout<<"Starting queue size is: "<<myqueue.size<<endl;
    int rand_req_time = 1 + rand() % 10;
    for(int clock_cycle = 0; clock_cycle < time_to_run; clock_cycle++){
        myserver.process_requests(clock_cycle);
        int empty_processor = myserver.find_empty_processor();
        if(rand_req_time == 0 || rand_req_time==-1){
            if(!myqueue.empty()){
                    Request* newReq = myqueue.requests.front();
                    if(empty_processor != -1 ){
                        myserver.take_in_request(newReq, empty_processor);
                        myqueue.pop();
                    }
                
            }                
        } else if(rand_req_time < 0){
            rand_req_time = 1 + rand() % 10;
        }    
        rand_req_time--; 
    }
    cout<<"Ending queue size is: "<<myqueue.size<<endl;
}


#endif /* MY_CLASS_H */