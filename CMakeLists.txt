cmake_minimum_required(VERSION 3.10)

# Project name and version
project(clsh VERSION 1.0)

# Add your source files
set(SOURCES
    src/getline.c
    src/main.c
)

# Add the executable
add_executable(clsh ${SOURCES})

# Link the math library (without this, it won't compile on FreeBSD)
target_link_libraries(clsh m)

# Add subdirectory for libs
add_subdirectory(lib)

# Link the Lua library (ensure this is available and correctly built)
target_link_libraries(clsh lua_static)

# Include the Lua headers
target_include_directories(clsh PRIVATE lua/src)
