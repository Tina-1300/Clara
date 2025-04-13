#include "../../include/Clara/ArgumentParser.hpp"
#include <stdexcept>

namespace Clara{
    
    ArgumentParser::ArgumentParser(int argc, char* argv[]){
        for (int i = 0; i < argc; ++i){
            args.push_back(argv[i]);
        }
    };

    void ArgumentParser::parse(){
        for (size_t i = 1; i < args.size(); ++i){
            const std::string& arg = args[i];
            // vérifier si il y à le symbole - pour indiquer le nom de paramètre ou --
            if (arg.substr(0, 1) == "-"){ 
                std::string option = arg;
                //std::string value = "";
                std::any value;
                if (i + 1 < args.size() && args[i + 1].substr(0, 1) != "-"){
                    value = args[i + 1];
                    ++i;
                }
                options[option] = value;
            }
        }
    };

    bool ArgumentParser::has_param(const std::string& option) const{
        return options.find(option) != options.end();
    };


    // corriger error des types 
    // on doit pouvoire parser les valeur passé aux paramètre de n'importe quelle type que ce 
    // soit int, bool, ect...
    
    template <typename T>
    T ArgumentParser::get_value_param(const std::string& option) const {
        auto it = options.find(option);
        if (it == options.end()){
            throw std::invalid_argument("Option non trouver : " + option);
        }
    
        const std::any& value = it->second;
    
        if constexpr (std::is_same<T, std::string>::value){
            return std::any_cast<std::string>(value);
        }
        
        else if constexpr (std::is_same<T, int>::value){
            return std::stoi(std::any_cast<std::string>(value));
        }
        
        else if constexpr (std::is_same<T, size_t>::value){
            return static_cast<size_t>(std::stoull(std::any_cast<std::string>(value)));
        }
        
        else if constexpr (std::is_same<T, bool>::value){
            std::string val = std::any_cast<std::string>(value);
            return val == "1" || val == "0" || val == "true" || val == "True";
        }
        
        else{
            throw std::invalid_argument("Mauvais type pour l'option : " + option);
        }
    }

    void ArgumentParser::set_param(Param& param) const {
        if(param.required == true){
            if(!has_param(param.option)){
                throw std::invalid_argument("param not found : " + param.option); 
            }
        }else{
            if(!has_param(param.option)){

            }
        }
    };


    size_t ArgumentParser::size() const{
        return args.size();
    };

    std::string ArgumentParser::getArg(size_t index) const{
        if (index < args.size()){
            return args[index];
        }
        return "";
    };
    
    std::unordered_map<std::string, std::any> ArgumentParser::getOptions() const{
        return options;
    };

    template std::string ArgumentParser::get_value_param<std::string>(const std::string& option) const;
    template int ArgumentParser::get_value_param<int>(const std::string& option) const;
    template bool ArgumentParser::get_value_param<bool>(const std::string& option) const;
    template size_t ArgumentParser::get_value_param<size_t>(const std::string& option) const;

};