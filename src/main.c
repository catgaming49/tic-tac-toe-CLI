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
    initGame(gameptr);
    int exit = 0;
    while (!exit) {
        playerSelect(gameptr);
        if (checkBoardRemaining(gameptr) >= 9) {
            endGame(gameptr, &exit);
        }
        //printf("benn %i %i\n", exit, checkBoardRemaining(gameptr));
        // if (!returnval) {
        //     // printf("An error occured during player selection\n");
        //     returnval = playerSelect(gameptr);
        // }
    AIselect(gameptr);
    renderBoard(gameptr);
    printf("Is there a winner? %i \n", checkForWinner(gameptr));
    }
    return 0;
}
