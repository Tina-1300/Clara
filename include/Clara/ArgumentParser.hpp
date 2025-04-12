#pragma once

#include "interfaces/IArgumentParser.hpp"
#include <vector>

namespace Clara{

    // Classe d'analyse des arguments
    class ArgumentParser : public IArgumentParser{
    public:
        ArgumentParser(int argc, char* argv[]);
        void parse() override;
        bool hasOption(const std::string& option) const override;

        template <typename T>
        T getOptionValue(const std::string& option) const;
        
        size_t size() const override;
        std::string getArg(size_t index) const override;

        
        std::unordered_map<std::string, std::any> getOptions() const override;

    private:
        std::vector<std::string> args;
        
        std::unordered_map<std::string, std::any> options;
        
    };

};