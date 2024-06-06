cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(ChessGame)

# Versión de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Rutas a las bibliotecas y encabezados de SFML
set(SFML_DIR "C:/SFML/lib/cmake/SFML")  # Ajusta esto a la ruta donde instalaste SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Incluir directorios
include_directories(${SFML_INCLUDE_DIR})

# Archivos fuente del proyecto
set(FILES
    board.cpp
    board.h
    chessGame.cpp
    chessGame.h
    main.cpp
    piece.cpp
    piece.h
    pieceTextures.cpp
    pieceTextures.h
)

add_executable(${CMAKE_PROJECT_NAME} ${FILES})

# Enlazar SFML con el ejecutable
target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics sfml-window sfml-system)
