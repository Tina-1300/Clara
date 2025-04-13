#pragma once

#include "ArgumentParser.hpp"
#include "ArgumentPrinter.hpp"

namespace Clara{

    // Classe pour l'usage simplifié des arguments
    class CommandLineArgs{
    public:
        CommandLineArgs(int argc, char* argv[]);
        
        bool has_param(const std::string& option) const;

        template <typename T>
        T get_value_param(const std::string& option) const{
            return parser.get_value_param<T>(option);
        };
        
        void set_param(Param& param) const;

        void printArgs() const;
        void printOptions() const;

    private:
        Clara::ArgumentParser parser;
        Clara::ArgumentPrinter printer;
    };

};