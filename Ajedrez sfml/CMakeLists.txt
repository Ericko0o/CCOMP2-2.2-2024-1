cmake_minimum_required(VERSION 3.26)
project(PruebaCLion)

set(CMAKE_CXX_STANDARD 17)

add_executable(PruebaCLion main.cpp
        board.h
        board.cpp
        chessGame.cpp
        chessGame.h
        piece.h
        piece.cpp
        pieceTextures.h
        pieceTextures.cpp
        Piece_hijas.h
        Piece_hijas.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML/lib/cmake/SFML")
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML)
target_link_libraries(PruebaCLion sfml-system sfml-window sfml-graphics sfml-audio)

