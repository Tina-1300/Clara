{
    files = {
        [[..\tests\test_clara.cpp]]
    },
    values = {
        [[C:\mingw64\bin\x86_64-w64-mingw32-g++]],
        {
            "-fvisibility=hidden",
            "-fvisibility-inlines-hidden",
            "-O3",
            "-std=c++20",
            [[-I..\include]],
            [[-Ibuild\1.0.0\Windows\Release\Clara\include]],
            "-fexceptions",
            "-O2",
            "-Os",
            "-s"
        }
    },
    depfiles_gcc = "test_clara.o: ..\\tests\\test_clara.cpp ..\\include/Clara/Clara.hpp  ..\\include/Clara/ClaraArgs/CommandLineArgs.hpp  ..\\include/Clara/ClaraArgs/ArgumentParser.hpp  ..\\include/Clara/ClaraArgs/IArgumentParser.hpp  ..\\include/Clara/ClaraArgs/ArgumentPrinter.hpp\
"
}