#pragma once

#include <string>
#include <unordered_map>

namespace Clara{

    // Interface pour l'analyse des arguments
    class IArgumentParser{
        public:
            virtual void parse() = 0;
            virtual bool hasOption(const std::string& option) const = 0;
            virtual std::string getOptionValue(const std::string& option) const = 0;
            virtual size_t size() const = 0;
            virtual std::string getArg(size_t index) const = 0;
            virtual std::unordered_map<std::string, std::string> getOptions() const = 0;
    };

};