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

    playerSelect(gameptr);

    renderBoard(gameptr);
    checkBoardRemaining(gameptr);
    setRandom(gameptr);

    Sleep(1000);
    renderBoard(gameptr);
    checkBoardRemaining(gameptr);

    Sleep(1000);
    setRandom(gameptr);
    renderBoard(gameptr);
    checkBoardRemaining(gameptr);
    return 0;
}