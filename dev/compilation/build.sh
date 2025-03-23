#!/bin/bash

# Vérifier si le dossier .xmake existe et le supprimer
if [ -d ".xmake" ]; then
    rm -rf .xmake
    echo "Dossier .xmake supprimer."
else
    echo "Le dossier .xmake n'existe pas."
fi

# Vérifier si le dossier build existe et le supprimer
if [ -d "build" ]; then
    rm -rf build
    echo "Dossier build supprimer."
else
    echo "Le dossier build n'existe pas."
fi

# Configurer xmake pour le mode release
xmake f -m release

# Compiler avec xmake
xmake

# Pause pour garder la fenêtre ouverte (optionnel)
read -p "Appuyez sur une touche pour continuer..."
