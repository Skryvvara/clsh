cmake_minimum_required(VERSION 3.10)

# Project name and version
project(clsh VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add your source files
set(SOURCES
    src/main.c
)

# Add subdirectory for libs
add_subdirectory(lib)

# Add the executable
add_executable(clsh ${SOURCES})

# Link the Lua library
target_link_libraries(clsh lua_static)

# Include the Lua headers
target_include_directories(clsh PRIVATE lua/src)

# Optionally, specify where to install the executable and other files
#install(TARGETS clsh DESTINATION bin)
