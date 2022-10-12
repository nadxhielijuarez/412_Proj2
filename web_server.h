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
 * @brief A dynamic array
 * 
 */
class Web_Server{
    int server_size;
    Request* server;/*should point to the array of that size*/
    Web_Server(int size);
    void fill_next_available_slot();

};

Web_Server::Web_Server(int size){
    server_size = size;
    server = new Request[size];
}


#endif /* MY_CLASS_H */