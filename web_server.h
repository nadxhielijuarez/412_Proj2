#ifndef WEB_SERVER_H // include guard
#define  WEB_SERVER_H
#include "request.h"
#include "processor.h"
#include <iostream>
#include <vector>
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
    public:
    int server_size;
    //Request* server;/*should point to the array of that size*/
    vector<Processor*> server;
    Web_Server(int size);
    Web_Server();
    //int process_requests(Request newRequest,  int max_req_time, int starting_index);
    void process_requests();
    void take_in_request(Request newRequest);
    int get_empty_indx();

};
/**
 * @brief Construct a new Web_Server::Web_Server object, this instantiates my array to be of the size that is passed
 * 
 * @param size 
 */
Web_Server::Web_Server(int size){
    server_size = size;
    for (int i=0; i<server_size;i++){
        Processor* processor = new Processor(i);
        server.push_back(processor);
    }
}

Web_Server::Web_Server(){
    server_size = 0;
}


void Web_Server::process_requests(){
    for(int indx=0; indx<server_size; indx++){
        Processor* cur_process = server[indx];
        if(!cur_process->empty){
            Request cur_request = cur_process->request_held;
            cur_request.time--;
            if(cur_request.time == 0){
                cur_process->empty = true;
            }
        }        
    }
}
int Web_Server::get_empty_indx(){
   // cout<<"called get empty index"<<endl;
    int processed_index = -1;
    for(int indx =0; indx<server_size; indx++){
        Processor* cur_processor = server[indx];
        if(cur_processor->empty==1){
            cout<<"at index "<<indx <<" server is "<<cur_processor->empty<<endl;
            processed_index = indx;
            break;
        } 
    }
    return processed_index;
}
void Web_Server::take_in_request(Request newRequest){
    
    int empty_slot_indx = get_empty_indx();
    if(empty_slot_indx != -1){
     //   cout<<"Empty slot: "<<empty_slot_indx<<endl;
        Processor*cur_processor = server[empty_slot_indx];
        //cout<<"old? "<<cur_processor->empty<<endl;
        Request old_Request = cur_processor->request_held;
        cur_processor->take_in_req(newRequest);
        cout<<"Old: "<<old_Request.input_IP<<" New "<< cur_processor->request_held.input_IP<<endl;
        //cout<<"Updated? "<<cur_processor->empty<<endl;        
    }

    
}




#endif /* MY_CLASS_H */