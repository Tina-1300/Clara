cmake_minimum_required(VERSION 3.10)

project(Clara)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SOURCES
    src/Clara/ArgumentParser.cpp
    src/Clara/ArgumentPrinter.cpp 
    src/Clara/CommandLineArgs.cpp 
)


set(HEADERS
    include/Clara/Clara.hpp
    include/Clara/ArgumentParser.hpp
    include/Clara/ArgumentPrinter.hpp
    include/Clara/CommandLineArgs.hpp
    include/Clara/interfaces/IArgumentParser.hpp   
)

# Créer la bibliothèque statique
add_library(Clara STATIC ${SOURCES} ${HEADERS})

# Ajouter des options de compilation (par exemple, pour activer les optimisations)
target_compile_options(Clara PRIVATE     
    -O2                  # Optimisation
    -Wall                # Affiche la plupart des avertissements
    -Wextra              # Avertissements supplémentaires
    -g                   # Informations de débogage
)

# Linker les option l'ors de la compilation de la library static
#target_link_libraries(Clara PRIVATE ws2_32)

target_include_directories(Clara PUBLIC ${PROJECT_SOURCE_DIR}/include)


# Définir le répertoire de sortie pour la bibliothèque compilée
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Définir l'emplacement d'installation
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/Clara)

# Ajouter un dossier pour les fichiers d'en-tête
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

# Installer la bibliothèque dans le dossier lib/
install(TARGETS Clara DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

#partie des unit test

enable_testing()
add_subdirectory(tests)

#cmake ..
#cmake --build .
#cmake --install .
#del /f /s /q *.* & for /d %i in (*) do rd /s /q "%i"
