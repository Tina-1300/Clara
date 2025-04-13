#include "../../include/Clara/CommandLineArgs.hpp"

namespace Clara{

    CommandLineArgs::CommandLineArgs(int argc, char* argv[]) : parser(argc, argv), printer(parser){
        parser.parse();
    };

    bool CommandLineArgs::hasOption(const std::string& option) const{
        return parser.hasOption(option);
    }



    void CommandLineArgs::printArgs() const{
        printer.printArgs();
    };

    void CommandLineArgs::printOptions() const{
        printer.printOptions();
    };


};
