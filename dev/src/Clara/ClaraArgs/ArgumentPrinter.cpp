#include "../../../include/Clara/ClaraArgs/ArgumentPrinter.hpp"
#include <iostream>

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
            std::cout << "Option " << option.first << " : " << option.second << "\n";
        }
    };

};