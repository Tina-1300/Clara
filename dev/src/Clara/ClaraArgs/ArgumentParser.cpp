#include "../../../include/Clara/ClaraArgs/ArgumentParser.hpp"

namespace Clara{
    
    ArgumentParser::ArgumentParser(int argc, char* argv[]){
        for (int i = 0; i < argc; ++i){
            args.push_back(argv[i]);
        }
    };

    void ArgumentParser::parse(){
        for (size_t i = 1; i < args.size(); ++i){
            const std::string& arg = args[i];
            if (arg.substr(0, 1) == "-"){ 
                std::string option = arg;
                std::string value = "";
                if (i + 1 < args.size() && args[i + 1].substr(0, 1) != "-"){
                    value = args[i + 1];
                    ++i;
                }
                options[option] = value;
            }
        }
    };

    bool ArgumentParser::hasOption(const std::string& option) const{
        return options.find(option) != options.end();
    };

    std::string ArgumentParser::getOptionValue(const std::string& option) const{
        auto it = options.find(option);
        if (it != options.end()){
            return it->second;
        }
        return "";
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
    
    std::unordered_map<std::string, std::string> ArgumentParser::getOptions() const{
        return options;
    };

};