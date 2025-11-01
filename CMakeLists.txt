# CMake configuration for rogue

cmake_minimum_required(VERSION 3.10)
project(rogue VERSION 5.4.5)

# Set the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Compiler flags
set(CMAKE_C_FLAGS "-g -O2")

# Include directories
include_directories(${CMAKE_SOURCE_DIR})

# Source files
set(SOURCES
    vers.c extern.c armor.c chase.c command.c daemon.c
    daemons.c fight.c init.c io.c list.c mach_dep.c
    main.c mdport.c misc.c monsters.c move.c new_level.c
    options.c pack.c passages.c potions.c rings.c rip.c
    rooms.c save.c scrolls.c state.c sticks.c things.c
    weapons.c wizard.c xcrypt.c
)

# Headers
set(HEADERS
    rogue.h extern.h score.h
)

# Executable
add_executable(rogue ${SOURCES} ${HEADERS})

# Libraries
# Uncomment and modify if additional libraries are needed
# target_link_libraries(rogue curses)

# Link the curses library
find_package(Curses REQUIRED)
target_link_libraries(rogue ${CURSES_LIBRARIES})

# Installation paths
set(CMAKE_INSTALL_PREFIX "/usr/local")
install(TARGETS rogue DESTINATION bin)
install(FILES rogue.6 DESTINATION share/man/man6)
install(FILES LICENSE.TXT DESTINATION share/doc/rogue)
install(FILES rogue.doc rogue.html rogue.cat rogue.me DESTINATION share/doc/rogue)

# Custom targets for cleaning and packaging
add_custom_target(distclean
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E remove rogue.scr rogue.lck
)

add_custom_target(dist
    COMMAND tar -czf ${PROJECT_NAME}-${PROJECT_VERSION}.tar.gz ${CMAKE_SOURCE_DIR}
)

# Simplify platform-specific definitions
add_definitions(
    -DHAVE_CONFIG_H
)