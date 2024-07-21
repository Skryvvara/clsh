#include <stdio.h>
#include <stdlib.h>
#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"

#define EXIT_FAILURE_PARAMETERS 2

int main(int argc, char* argv[]) {

    if (argc < 2) {
        char* name = argv[0];
        fprintf(stderr, "usage: %s [file]\n", name);
        exit(EXIT_FAILURE_PARAMETERS);
    }

    char* file_name = argv[1];

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    luaL_dofile(L, file_name);

    lua_close(L);
    exit(EXIT_SUCCESS);
}
