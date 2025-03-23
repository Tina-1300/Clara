{
    files = {
        [[..\src\Clara\ClaraArgs\ArgumentPrinter.cpp]]
    },
    values = {
        [[C:\mingw64\bin\x86_64-w64-mingw32-g++]],
        {
            "-fvisibility=hidden",
            "-fvisibility-inlines-hidden",
            "-O3",
            "-std=c++20",
            [[-I..\include]],
            "-fexceptions",
            "-O2",
            "-Os",
            "-s"
        }
    },
    depfiles_gcc = "ArgumentPrinter.o: ..\\src\\Clara\\ClaraArgs\\ArgumentPrinter.cpp  ..\\src\\Clara\\ClaraArgs\\../../../include/Clara/ClaraArgs/ArgumentPrinter.hpp  ..\\src\\Clara\\ClaraArgs\\../../../include/Clara/ClaraArgs/IArgumentParser.hpp\
"
}