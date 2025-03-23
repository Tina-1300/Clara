{
    files = {
        [[..\src\Clara\ClaraArgs\ArgumentParser.cpp]]
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
    depfiles_gcc = "ArgumentParser.o: ..\\src\\Clara\\ClaraArgs\\ArgumentParser.cpp  ..\\src\\Clara\\ClaraArgs\\../../../include/Clara/ClaraArgs/ArgumentParser.hpp  ..\\src\\Clara\\ClaraArgs\\../../../include/Clara/ClaraArgs/IArgumentParser.hpp\
"
}