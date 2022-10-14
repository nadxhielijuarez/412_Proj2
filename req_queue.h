
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
    queue<Request*> requests;
    Req_Queue(int servers);
    Req_Queue();
    Request* pop();
    bool empty();
};

/**
 * @brief Construct a new Req_Queue::Req_Queue object
 * creates a queue of type request pointers, request*. The queue then gets populated with 2*(number of servers) requests. Making use of dynamic memory ensures that variables are
 * updated as expected.
 * 
 * @param servers - an integer
 */
Req_Queue::Req_Queue(int servers){
    int find_max_time = -1;
    size = 2*servers;
    for(int i=0; i<size; i++){
        Request* newRequest= new Request;
        requests.push(newRequest);
        if(find_max_time< newRequest->time){
            find_max_time = newRequest->time;
        }
    }
    max_time = find_max_time;
}

/**
 * @brief Construct a new Req_Queue::Req_Queue object this is a default constructor that creates an empty queue of size 0
 * 
 */
Req_Queue::Req_Queue(){
    max_time = -1;
    size = 0;
}

/**
 * @brief This pop function pops off elements from the underlying queue, returns the element that was just deleted, and decrements the size of our queue.
 * 
 * @return Request* 
 */
Request* Req_Queue::pop(){
    Request* myReq = requests.front();
    requests.pop();
    size--;
    return myReq;
}
/**
 * @brief This is just a re-iteration of the underlying queue's empty, its easier to read and work with
 * 
 * @return bool 
 */
bool Req_Queue::empty(){
    return requests.empty();
}

#endif 