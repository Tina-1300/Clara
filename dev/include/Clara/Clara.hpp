#pragma once

#if defined(_WIN32) || defined(_WIN64)

    #ifdef INCLUDE_CLARA
        #include "ClaraArgs/CommandLineArgs.hpp" // module : getion des arguments en CLI
    #endif

    


#else
    #error "Unsupported operating system !"    
#endif