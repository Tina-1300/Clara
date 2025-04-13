#include "../../include/Clara/CommandLineArgs.hpp"

namespace Clara{

    CommandLineArgs::CommandLineArgs(int argc, char* argv[]) : parser(argc, argv), printer(parser){
        parser.parse();
    };

    bool CommandLineArgs::has_param(const std::string& option) const{
        return parser.has_param(option);
    }

    void CommandLineArgs::set_param(Param& param) const{
        parser.set_param(param);
    }

    void CommandLineArgs::printArgs() const{
        printer.printArgs();
    };

    void CommandLineArgs::printOptions() const{
        printer.printOptions();
    };


};
