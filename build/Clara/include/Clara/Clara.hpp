#pragma once

#if defined(_WIN32) || defined(_WIN64)
    
    #include "CommandLineArgs.hpp"
    

#else
    #error "Unsupported operating system !"    
#endif