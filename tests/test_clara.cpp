#define INCLUDE_CLARA
#include <iostream>
#include "Clara/Clara.hpp"

#include <any>

// g++ -Os -s -o test.exe test.cpp -lClara & color

int main(int argc, char *argv[]){

    Clara::CommandLineArgs clara(argc, argv);

    Clara::Param ip_param;
    ip_param.option = "--ip";
    ip_param.required = true;

    Clara::Param nline_param;
    nline_param.option = "-nline";
    nline_param.required = false;

    Clara::Param port_param;
    port_param.option = "-port";
    port_param.required = true;



    clara.set_param(ip_param);
    clara.set_param(port_param);
    clara.set_param(nline_param);

    
    std::string ipValue = clara.get_value_param<std::string>("--ip");
    std::string portValue = clara.get_value_param<std::string>("-port");


    std::cout << "IP address : " << ipValue <<":"<< portValue << "\n";
    

    if(clara.has_param("-nline") == true){
        int number_line = clara.get_value_param<int>("-nline");
        std::cout << "Number line of file max : " << number_line << "\n";
    }

    //lara.printArgs();
    //clara.printOptions();

};