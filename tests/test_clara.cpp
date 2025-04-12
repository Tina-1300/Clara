#define INCLUDE_CLARA
#include <iostream>
#include "Clara/Clara.hpp"

#include <any>

// g++ -Os -s -o test.exe test.cpp -lClara & color

int main(int argc, char *argv[]){

    Clara::CommandLineArgs clara(argc, argv);

    if(clara.hasOption("--ip") == true){
        std::any ipValue;
        std::string(ipValue) = clara.getOptionValue("--ip");

        std::cout << "IP address : " << ipValue << "\n";
    }

    //lara.printArgs();
    //clara.printOptions();

};