#pragma once

#include <string>
#include <unordered_map>

#include <any>

#include <vector>

namespace Clara{

    struct Param{
        std::string option;
        bool required;
    };

    // Interface pour l'analyse des arguments
    class IArgumentParser{
        public:
            virtual void parse() = 0;
            
            virtual bool has_param(const std::string& option) const = 0; // has_param
            
            
            template <typename T>
            T get_value_param(const std::string& option) const; // get_value_param

            virtual void set_param(Param& param) const = 0;

            //virtual void set_params(std::vector<Param>& params) const = 0; // liste de paramètre à definir

            virtual size_t size() const = 0;
            virtual std::string getArg(size_t index) const = 0;
 
            virtual std::unordered_map<std::string, std::any> getOptions() const = 0;

    };

};