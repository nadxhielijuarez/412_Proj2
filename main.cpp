#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "web_server.h"
#include "request.h"
#include "load_balancer.h"
#include "req_queue.h"

using namespace std;
int main(int argc, char *argv[]){
    /*
    User input:
    - time to run load balancer, in microseconds, max is 100000

    queue gets instantiated with server*2 random requests

    the load balancer comes into to play to select which request to put into the web_server
    web server will hold request for the time alloted then it'll print the processed request to the one its taking in

    number of servers
    */
   int servers;
   int lb_time;
   int c;
    while ((c = getopt (argc, argv, "s:t:")) != -1){
            switch (c){
                case 's':
                    servers = atoi (optarg);
                    break;
                case 't':
                    lb_time = atoi (optarg);
                // cout<<"read in m?"<<endl;
                    break;
    }

   Req_Queue myQ(servers);
   Web_Server myServer(servers);
   Load_Balancer myLB(myQ, myServer, lb_time);

   cout<<"\n Beginning to allocate requests, requests time vary from 0-1000"<<endl;
   myLB.allocate_requests();  
    }
}