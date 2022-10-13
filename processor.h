#ifndef PROCESSOR_H // include guard
#define PROCESSOR_H
#include <iostream>
#include "request.h"

class Processor{
public:
    Request request_held;
    bool empty;
    int name;
    
    Processor();
    Processor(int nname);
    void take_in_req(Request req);
};

Processor::Processor(){
    empty = true;
    name = -1;
}

Processor::Processor(int nname){
    name = nname;
    empty = true;
}

void Processor::take_in_req(Request req){
    request_held = req;
    empty = false;
}

#endif 