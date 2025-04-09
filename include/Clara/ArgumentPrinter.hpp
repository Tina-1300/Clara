#pragma once

#include "interfaces/IArgumentParser.hpp"

namespace Clara{

    // Classe d'affichage des arguments
    class ArgumentPrinter{
        public:
            ArgumentPrinter(const IArgumentParser& parser);
        
            void printArgs() const;
        
            void printOptions() const;
        
        private:
            const IArgumentParser& parser;
    };

};