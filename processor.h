#ifndef PROCESSOR_H // include guard
#define PROCESSOR_H
#include <iostream>
#include "request.h"

class Processor{
public:
    Request request_held;
    bool empty;
    int name;

    Processor(int newName);
    void take_in_req(Request req);
};



Processor::Processor(int newName){
    empty = true;
    Request req("","",0);
    request_held = req;
    name = -1;
}

void Processor::take_in_req(Request req){
    request_held = req;
    empty = false;
}

#endif 