cmake_minimum_required(VERSION 3.10)

include(CheckLibraryExists)

# Project name and version
project(clsh VERSION 1.0)

# Add your source files
set(SOURCES
    src/getline.c
    src/main.c
)

# Add the executable
add_executable(clsh ${SOURCES})

CHECK_LIBRARY_EXISTS(m sin "" HAVE_LIB_M)

# Add subdirectory for libs
add_subdirectory(lib)

# Link the Lua library (ensure this is available and correctly built)
set(EXTRA_LIBS ${EXTRA_LIBS} lua_static)

target_link_libraries(clsh PUBLIC ${EXTRA_LIBS})

# Include the Lua headers
target_include_directories(clsh PRIVATE lua/src)
