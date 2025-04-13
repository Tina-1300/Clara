#pragma once

#include <string>
#include <unordered_map>

#include <any>

namespace Clara{

    // Interface pour l'analyse des arguments
    class IArgumentParser{
        public:
            virtual void parse() = 0;
            virtual bool hasOption(const std::string& option) const = 0;
            
            template <typename T>
            T getOptionValue(const std::string& option) const;


            virtual size_t size() const = 0;
            virtual std::string getArg(size_t index) const = 0;
 
            virtual std::unordered_map<std::string, std::any> getOptions() const = 0;

    };

};