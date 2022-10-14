#ifndef Request_H // include guard
#define Request_H 

#include <iostream>

using namespace std;
class Request{
public:
    string input_IP;
    string output_IP;
    int time;

    Request();
    Request(string in_IP, string out_IP, int time);
    string generate_num_for_IP();
    string Generate_IP();
    int generate_time();

};

/**
 * @brief 
 * Generating a random int from 0 to 255, converting that into a string  
 * then returning the string value
 * 
 * @return string: random number from 0 to 255, to later be used in IP
 */

string Request::generate_num_for_IP(){
    /**This function generates a random integer from 0 to 255 and returns that integer as a string*/
    int num1 = rand() % 255 + 0;
    string return_num = to_string(num1);
    return return_num;
}

/**
 * @brief Obtaining a random IP
 * 
 * @return string random IP 
 */
string Request::Generate_IP(){
    string ip = generate_num_for_IP() + "." + generate_num_for_IP() + "." + generate_num_for_IP() + "." + generate_num_for_IP();
    return ip;
}

/**
 * @brief Generating a random time
 * 
 * @return int a random time
 */
int Request::generate_time(){
    int micro_second = rand() % 1000 + 1;
    return micro_second;
}

/**
 * @brief Construct a new Request:: Request object
 * creates a random request object every time its called
 * 
 */

Request::Request(){
    input_IP = Generate_IP();
    output_IP = Generate_IP();
    time = generate_time();
};





#endif 