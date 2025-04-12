#pragma once

#include "ArgumentParser.hpp"
#include "ArgumentPrinter.hpp"

namespace Clara{

    // Classe pour l'usage simplifié des arguments
    class CommandLineArgs{
    public:
        CommandLineArgs(int argc, char* argv[]);
        
        bool hasOption(const std::string& option) const;

        template <typename T>
        T getOptionValue(const std::string& option) const;
        
        void printArgs() const;
        void printOptions() const;

    private:
        Clara::ArgumentParser parser;
        Clara::ArgumentPrinter printer;
    };

};