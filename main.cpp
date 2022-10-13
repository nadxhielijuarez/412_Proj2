#include <iostream>
#include "web_server.h"
#include "request.h"
#include "load_balancer.h"
#include "req_queue.h"

using namespace std;
int main(){
    /*
    User input:
    - time to run load balancer, in microseconds, max is 100000
    - number of servers
    */
   cout<<"Enter the number of servers you would like"<<endl;
   string str_servers; 
   cin>>str_servers;
   int servers = stoi(str_servers);
   cout<<"read in: "<<str_servers<<" servers" <<endl;

   cout<<"Enter the time for which you would like to run the load_balancer in microseconds, max is 100000"<<endl;
   string str_lb_time;
   cin>> str_lb_time;
   int lb_time = stoi(str_lb_time);
   cout<<"read in: "<<str_lb_time<<" load balancer time " <<endl;

   Req_Queue myQ(servers);

//    cout<<"queue made: "<<endl;
//    for(int i=0; i< servers;i++){
//     Request* req = myQ.requests.front();
//     cout<<"req: "<<req->input_IP<<endl;
//     myQ.pop();
//    }
   Web_Server myServer(servers);
  Load_Balancer myLB(myQ, myServer, lb_time);

//    cout<<"checking server:"<<endl;

//    for(int i = 0; i<servers; i++){
//     cout<<"renamed?"<<myServer.server[i].name<<endl;
//    }



   cout<<"\n Beginning to allocate requests"<<endl;
   myLB.allocate_requests();

}
/*
queue gets instantiated with server*2 random requests

the load balancer comes into to play to select which request to put into the web_server
web server will hold request for the time alloted then it'll print the processed request to the one its taking in

*/