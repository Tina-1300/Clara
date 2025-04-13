#pragma once

#include "interfaces/IArgumentParser.hpp"
#include <vector>

namespace Clara{

    // Classe d'analyse des arguments
    class ArgumentParser : public IArgumentParser{
    public:
        ArgumentParser(int argc, char* argv[]);
        void parse() override;
        bool has_param(const std::string& option) const override;

        template <typename T>
        T get_value_param(const std::string& option) const;
        
        void set_param(Param& param) const override;

        size_t size() const override;
        std::string getArg(size_t index) const override;

        
        std::unordered_map<std::string, std::any> getOptions() const override;

    private:
        std::vector<std::string> args;
        
        std::unordered_map<std::string, std::any> options;
        
    };

};