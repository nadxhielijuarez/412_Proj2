#ifndef WEB_SERVER_H // include guard
#define  WEB_SERVER_H
#include "request.h"
#include "processor.h"
#include <iostream>
using namespace std;
/*
dynamically allocated array of servers, the # of servers is given by the user in ther terminal
have a function to find empty servers or empty array slots, so that requests can be popped in and popped out correctly
pops out onto the terminal
request inside server just deletes when time is over
*/

/**
 * @brief THis is essentially a dynamic array
 * 
 */
class Web_Server{
    int server_size;
    //Request* server;/*should point to the array of that size*/
    Processor* server;
    public:
    Web_Server(int size);
    Web_Server();
    //int process_requests(Request newRequest,  int max_req_time, int starting_index);
    void process_requests();
    void take_in_Request(Request newRequest);
    int get_empty_indx();

};
/**
 * @brief Construct a new Web_Server::Web_Server object, this instantiates my array to be of the size that is passed
 * 
 * @param size 
 */
Web_Server::Web_Server(int size){
    server_size = size;
   for(int i=0; i<size; i++){
    server[i] = Processor(i);
   }
}

Web_Server::Web_Server(){
    server_size = 0;
    server = NULL;
}


void Web_Server::process_requests(){
    for(int indx=0; indx<server_size; indx++){
        Processor cur_process= server[indx];
        if(!cur_process.empty){
            Request cur_request = cur_process.request_held;
            cur_request.time--;
            if(cur_request.time == 0){
                cur_process.empty = true;
            }
        }        
    }
}
int Web_Server::get_empty_indx(){
    int processed_index = 0;
    for(int indx =0; indx<server_size; indx++){
        Processor cur_processor = server[indx];
        if(cur_processor.empty){
            processed_index = indx;
            break;
        }
    }
    return processed_index;
}
void Web_Server::take_in_Request(Request newRequest){
    
    int empty_slot_indx = get_empty_indx();
    Processor cur_processor = server[empty_slot_indx];
    Request old_Request = cur_processor.request_held;
    cout<<"processor "<< cur_processor.name<<" processed "<<old_Request.output_IP <<" and beginning "<<newRequest.input_IP<<endl;
    cur_processor.take_in_req(newRequest);
}




#endif /* MY_CLASS_H */