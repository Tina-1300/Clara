#include "../../../include/Clara/ClaraArgs/CommandLineArgs.hpp"

namespace Clara{

    CommandLineArgs::CommandLineArgs(int argc, char* argv[]) : parser(argc, argv), printer(parser){
        parser.parse(); // parser les arguments à l'initialisation de la class
    };

    bool CommandLineArgs::hasOption(const std::string& option) const{
        return parser.hasOption(option);
    }

    std::string CommandLineArgs::getOptionValue(const std::string& option) const{
        return parser.getOptionValue(option);
    };

    void CommandLineArgs::printArgs() const{
        printer.printArgs();
    };

    void CommandLineArgs::printOptions() const{
        printer.printOptions();
    };

};
