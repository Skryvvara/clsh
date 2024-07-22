#include <stdio.h>
#include <stdlib.h>
#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"

#define EXIT_FAILURE_PARAMETERS 2

#ifdef _WIN32
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
#endif

char* read_line(void) {
    char* line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1) {
        if (feof(stdin)) {
            exit(EXIT_SUCCESS);
        } else {
            perror("readline");
            exit(EXIT_FAILURE);
        }
    }
    return line;
}

int main(int argc, char* argv[]) {
    char* line;
    char* file_name;

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    if (argc < 2) {
        printf("No script file provided, reading from STDIN\n");

        while (1) {
            line = read_line();
            luaL_dostring(L, line);
            free(line);
        }

        /*
        char* name = argv[0];
        fprintf(stderr, "usage: %s [file]\n", name);
        exit(EXIT_FAILURE_PARAMETERS);
        */
    } else {
        char* file_name = argv[1];

        lua_newtable(L);
        for(int i = 0; i < argc; i++) {
            lua_pushnumber(L, i);
            lua_pushstring(L, argv[i]);
            lua_settable(L, -3);
        }
        lua_setglobal(L, "arg");

        if (luaL_dofile(L, file_name) != LUA_OK) {
            const char* error = lua_tostring(L, -1);
            fprintf(stderr, "Error: %s\n", error);
            lua_pop(L, 1);
        }
    }

    lua_close(L);
    exit(EXIT_SUCCESS);
}
