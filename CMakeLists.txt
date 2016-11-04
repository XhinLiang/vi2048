cmake_minimum_required(VERSION 3.2)
project(vi_2048)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(SOURCE_FILES
        src/game.h src/high_score.h src/menu.h src/game_saving.h
        src/game.c src/high_score.c src/menu.c src/game_saving.c

        lib/random_number.h lib/random_number.c
        lib/direction.h lib/direction.c

        main.c lib/keys.h lib/keys.c src/print_tools.c src/print_tools.h)
add_executable(vi2048 ${SOURCE_FILES})