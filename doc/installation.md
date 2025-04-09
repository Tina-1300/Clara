# Installation de Clara

Pour installer la library `Clara`, vous aurez besoin de CMake.

Rendez-vous dans le répertoire build/. S'il n'existe pas, créez-le en exécutant la commande suivante à la racine du projet :

```bash
mkdir build && cd build
```

Ensuite, vous devez exécuter les commandes suivantes dans l'ordre indiqué ci-dessous :

1) Générer les fichiers de configuration avec CMake :

```bash
cmake ..
```

2) Compiler le projet :

```bash 
cmake --build .
```

3) Installer la library :

```bash 
cmake --install .
```

Après cela, dans le répertoire `build/`, un dossier nommé `Clara` sera créé, contenant deux sous-dossiers :
- `include/`
- `lib/`

Vous n'avez plus qu'à installer manuellement le contenu de ces deux répertoires dans les bons dossiers de votre installation MinGW.

## Compilation de votre exécutable

Pour compiler un exécutable qui utilise la library `Clara`, vous pouvez utiliser la commande suivante :
```
g++ -O2 -o main.exe main.cpp -lClara & color
```