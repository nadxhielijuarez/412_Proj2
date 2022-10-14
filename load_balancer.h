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
/**
 * @brief Construct a new Load_Balancer::Load_Balancer object
 * This object is what allocates requests from a queue, that is 2 times the number of servers we have
 * @param queue - a Req_Queue object, that is instantiated in the main file
 * @param server - Web_Server object that is also instantiated in main
 * @param time the amount of time for which we want to run the load balancer, defined by user and passed in from main
 */
Load_Balancer::Load_Balancer(Req_Queue queue, Web_Server server, int time){
    myqueue = queue;
    myserver = server;
    time_to_run = time;
}


void Load_Balancer::allocate_requests(){
    /**
     * @brief allocate requests is the function that pops requests off of the queue, and passes them into the web_server to process
     * this function works by processing requests every clock cycle, and at random times a new request is obtained
     * if there exists an empty processor, the new request gets taken in my the web_server otherwise we wait until there is an empty processor
     * 
     */
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



#endif /* MY_CLASS_H */