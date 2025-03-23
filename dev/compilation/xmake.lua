-- xmake f -c
-- xmake
--xmake f -m release

set_project("Clara")

-- configurer le compilateur pour MinGW
toolchain("mingw")
    set_kind("standalone") -- indique un compilateur indépendant
    set_sdkdir("C:/mingw64") -- chemin vers le répertoir MinGW
toolchain_end()

set_toolchains("mingw")

set_optimize("fastest") 
set_symbols("hidden") 

add_cxxflags("-O2", "-Os", "-s") 

target("Clara")
set_kind("static") -- génération library static 
set_languages("c++20")
add_includedirs("../include") -- ajouter les répertoir d'entête
add_files("../src/**.cpp") -- ajouter tout les fichiers sources de manière récursive 

-- répertoire de sortie pour la library 
set_targetdir("build/1.0.0/Windows/Release/Clara/lib")
    after_build(function (target)
        -- copier les chemin d'entête y comprit les sous dossier
        os.cp("../include/*", "build/1.0.0/Windows/Release/Clara/include/")
    end)

        
-- esseyer de Finire la compilation de la library avant de compiler les tests


-- Function pour les test unitaire
function setup_test(target_name, test_file, extra_links)
    target(target_name)
        set_kind("binary")
        set_languages("c++20")
        add_files(test_file)
        add_includedirs("../include", "build/1.0.0/Windows/Release/Clara/include/")
        add_linkdirs("build/1.0.0/Windows/Release/Clara/lib/")
        add_links("Clara")
        add_cxxflags("-O2", "-Os", "-s")

        if extra_links then
            for _, lib in ipairs(extra_links) do
                add_links(lib)
            end
        end
end


-- Unit test Registry Windows
setup_test("test_clara", "../tests/test_clara.cpp")

-- Unit test Speaker Windows 
--setup_test("test_speaker", "../tests/test_speaker.cpp", {"ole32"})

-- Unit test printer Windows
--setup_test("test_printer", "../tests/test_printer.cpp", {"winspool"})