#ifndef PROCESSOR_H // include guard
#define PROCESSOR_H
#include <iostream>
#include "request.h"

class Processor{
public:
    Request* request_held;
    bool empty;
    int name;
    
    Processor();
    Processor(int nname);
    void take_in_req(Request* req);
};

/**
 * @brief Construct a new Processor:: Processor object
 * this is a defualt constructor for processors, it instaniates an empty processor
 * 
 */
Processor::Processor(){
    empty = true;
    name = -1;
}

/**
 * @brief Construct a new Processor:: Processor object
 * this just ensures that the created processor has a name, that name is an int and its passed in by the user
 * @param nname - integer
 */
Processor::Processor(int nname){
    name = nname;
    empty = true;
}

/**
 * @brief This is where a processor takes in a request
 * when a new request gets taken in, the request held (pointer) is updated, and the processor is no longer empty
 * @param req, of type request
 */
void Processor::take_in_req(Request* req){
    request_held = req;
    empty = false;
}

#endif 