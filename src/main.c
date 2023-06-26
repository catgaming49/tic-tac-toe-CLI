#include<stdio.h>
#include<stdlib.h>
#include<gameutils.h>

#ifdef _WIN32
#include<windows.h>
#elif __linux__
#include<unistd.h>
#endif


int main() {
    Gameboard gameboard;
    Gameboard*gameptr = &gameboard;
    init_game(gameptr);
    int exit = 0;
    while (!exit) {
        int returnval = playerSelect(gameptr);
        while (!returnval) {
            returnval = playerSelect(gameptr);
        }
    renderBoard(gameptr);
    AIselect(gameptr);
    renderBoard(gameptr);
    }
    return 0;
}