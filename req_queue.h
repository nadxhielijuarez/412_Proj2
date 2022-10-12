
#ifndef MY_CLASS_H // include guard
#define MY_CLASS_H
#include <iostream>
#include <queue>
#include "request.h"

using namespace std;
class Req_Queue{
    Req_Queue(int servers);
    int max_time;
    int size;
    queue<Request> requests;
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
#endif 