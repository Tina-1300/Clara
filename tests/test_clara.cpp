#define INCLUDE_CLARA
#include <iostream>
#include "Clara/Clara.hpp"

#include <any>

// g++ -Os -s -o test.exe test.cpp -lClara & color

int main(int argc, char *argv[]){

    Clara::CommandLineArgs clara(argc, argv);

    if(clara.hasOption("--ip") == true){
        std::string ipValue = clara.getOptionValue<std::string>("--ip");

        std::cout << "IP address : " << ipValue << "\n";
    }

    if(clara.hasOption("-nline") == true){
        int number_line = clara.getOptionValue<int>("-nline");
        std::cout << "Number line of file max : " << number_line << "\n";
    }

    //lara.printArgs();
    //clara.printOptions();

};