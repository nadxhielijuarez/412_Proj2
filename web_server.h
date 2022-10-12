#ifndef WEB_SERVER_H // include guard
#define  WEB_SERVER_H
#include "request.h"
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
    Request* server;/*should point to the array of that size*/
    Web_Server(int size);
    ~Web_Server();
    int process_requests(Request newRequest,  int max_req_time, int starting_index);

};
/**
 * @brief Construct a new Web_Server::Web_Server object, this instantiates my array to be of the size that is passed
 * 
 * @param size 
 */
Web_Server::Web_Server(int size){
    server_size = size;
    server = new Request[size];
}
/**
 * @brief Destroy the Web_Server::Web_Server object Destructor
 * 
 */
Web_Server::~Web_Server(){
    delete [] server;
}

/**
 * @brief Servers to process all 
 * 
 * @param newRequest 
 * @param max_size 
 * @param starting_index 
 * @return int 
 */
int Web_Server::process_requests(Request newRequest, int max_size, int starting_index){
    int processed_index = 0;
    for(int i=starting_index; i<max_size; i++){
        for(int j=0; j<server_size; j++){
            Request cur_request = server[j];
            if(cur_request.time == i){
                processed_index = i;
                cout<<"Processed request: "<<cur_request.output_IP<<" begining "<<newRequest.input_IP <<endl;
                server[j] = newRequest; 
                break;
            }
        }
    }
    return processed_index;
}




#endif /* MY_CLASS_H */