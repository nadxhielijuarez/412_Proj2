#include <iostream>

using namespace std;
int main(){

    cout<<"Checking output"<<endl;
}
/*
queue gets instantiated with server*2 random requests

the load balancer comes into to play to select which request to put into the web_server
web server will hold request for the time alloted then it'll print the processed request to the one its taking in

*/