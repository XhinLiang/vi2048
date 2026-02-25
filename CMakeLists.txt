cmake_minimum_required(VERSION 3.16)

project(vi2048 VERSION 1.0.1 LANGUAGES C)

include(GNUInstallDirs)

add_executable(vi2048)

target_sources(vi2048
    PRIVATE
        main.c
        src/game.c
        src/game_saving.c
        src/high_score.c
        src/menu.c
        src/print_tools.c
        src/utils.c
        lib/direction.c
        lib/keys.c
        lib/random_number.c
)

target_compile_features(vi2048 PRIVATE c_std_99)
set_target_properties(vi2048 PROPERTIES C_EXTENSIONS OFF)

if(CMAKE_C_COMPILER_ID MATCHES "Clang|AppleClang|GNU")
    target_compile_options(vi2048 PRIVATE -Wall -Wextra -Wpedantic)
endif()

install(TARGETS vi2048 RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
