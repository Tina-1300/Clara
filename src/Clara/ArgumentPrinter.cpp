#include "../../include/Clara/ArgumentPrinter.hpp"
#include <iostream>

#include <any>
#include <typeinfo>

namespace Clara{

    ArgumentPrinter::ArgumentPrinter(const IArgumentParser& parser) : parser(parser) {};

    void ArgumentPrinter::printArgs() const{
        std::cout << "Number of arguments : " << parser.size() << "\n";
        for (size_t i = 0; i < parser.size(); ++i){
            std::cout << "Argument " << i << " : " << parser.getArg(i) << "\n";
        }
    };

    void ArgumentPrinter::printOptions() const{
        for (const auto& option : parser.getOptions()){
            std::cout << "Option " << option.first << " : ";
            if(option.second.type() == typeid(int)){
                std::cout << std::any_cast<int>(option.second);
            }else if (option.second.type() == typeid(std::string)){
                std::cout << std::any_cast<std::string>(option.second);
            }else if (option.second.type() == typeid(bool)){
                std::cout << (std::any_cast<bool>(option.second) ? "true" : "false");
            }else{
                std::cout << "Type inconnu";
            }
            std::cout << "\n";
        }
    };

};