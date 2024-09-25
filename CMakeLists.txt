make_minimum_required(VERSION 3.29)
project(cluedo-groupe-3-f-main)

set(CMAKE_CXX_STANDARD 14)

# Chemin vers SFML
set(SFML_DIR "C:/Users/mathe/OneDrive - Groupe INSEEC (POCE)/Bureau/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/cmake/SFML")

# Trouver les bibliothèques SFML
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Spécifie les répertoires pour les fichiers source et les en-têtes
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories("C:/Users/mathe/OneDrive - Groupe INSEEC (POCE)/Bureau/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/include")

# Ajoute les fichiers source (.cpp) depuis le dossier src
file(GLOB SOURCES "src/*.cpp")

# Ajoute l'exécutable
add_executable(cluedo-groupe-3-f-main ${SOURCES})

# Lier les bibliothèques SFML
target_link_libraries(cluedo-groupe-3-f-main
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
        sfml-network
)

# Spécifie le chemin vers les bibliothèques SFML
link_directories("C:/Users/mathe/OneDrive - Groupe INSEEC (POCE)/Bureau/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib")