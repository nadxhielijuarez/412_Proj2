
#ifndef REQ_QUEUE_H // include guard
#define REQ_QUEUE_H
#include <iostream>
#include <queue>
#include "request.h"

using namespace std;
class Req_Queue{
public:
    int max_time;
    int size;
    queue<Request> requests;
    Req_Queue(int servers);
    Req_Queue();
    Request pop();
    bool empty();
};

/**
 * @brief Might not need it
 * 
 */
Req_Queue::Req_Queue(int servers){
    int find_max_time = -1;
    size = 2*servers;
    for(int i=0; i<size; i++){
        Request newRequest;
        requests.push(newRequest);
        if(find_max_time< newRequest.time){
            find_max_time = newRequest.time;
        }
    }
    max_time = find_max_time;
}

Req_Queue::Req_Queue(){
    max_time = -1;
    size = 0;
}

Request Req_Queue::pop(){
    Request myReq = requests.front();
    requests.pop();
    return myReq;
}

bool Req_Queue::empty(){
    return requests.empty();
}

#endif 