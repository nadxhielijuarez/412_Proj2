#ifndef MY_CLASS_H // include guard
#define MY_CLASS_H

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
 * @brief A dynamic array
 * 
 */
class Web_Server{
    int emptyServer_indx;
    int server_size;
    Request[] *server;
    Web_Server();
    void fill_next_available_slot();
    


};


#endif /* MY_CLASS_H */