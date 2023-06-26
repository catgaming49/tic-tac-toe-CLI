#include<stdio.h>
#include<math.h>
#include<time.h>

#include<conio.h>

#include<stdlib.h>
#define boardsize 3

typedef struct Vector2 {
     int X;
     int Y;
}Vector2;

typedef struct Gameboard {
     int Board[3][3];
}Gameboard;

int constrict(int num) {
    if (num > boardsize) {
        return boardsize;
    }
    else if (num < 0)
    {
        return 0;
    }
    else {
        return num;
    }
    
}



void processVector(Vector2*pos) {
    pos->X = constrict(pos->X-1);
    pos->Y = constrict(pos->Y-1);
}

void clearBoard(Gameboard*gameboard) {
    for (int i = 0;i<3;i++) {
        gameboard->Board[0][i] = 0;
        gameboard->Board[1][i] = 0;
        gameboard->Board[2][i] = 0;
    }
}

void setBoard(Gameboard*gameboard, Vector2 pos, int val) {
    processVector(&pos);
    gameboard->Board[pos.X][pos.Y] = val;
}

void setBoardRaw(Gameboard*gameboard, Vector2 pos, int val) {
    printf("%i|%i", pos.X, pos.Y);
    gameboard->Board[pos.X][pos.Y] = val;
}

int readBoard(Gameboard*gameboard, Vector2 pos) {
    processVector(&pos);
    return gameboard->Board[pos.X][pos.Y];
}

void renderBoard(Gameboard*gameboard) {
    for (int i = 0;i<3;i++) {
         if (gameboard->Board[i][0]) {
            printf("#");
         }
         else {
            printf("O");
         }
    }
    printf("\n");
    for (int i = 0;i<3;i++) {
        if (gameboard->Board[i][1]) {
            printf("#");
         }
         else {
            printf("O");
         }
    }
    printf("\n");
    for (int i = 0;i<3;i++) {
        if (gameboard->Board[i][2]) {
            printf("#");
         }
         else {
            printf("O");
         }
    }
    printf("\n");

}

int checkSetBoard(Gameboard*gameboard, Vector2 pos) {
    processVector(&pos);
    if (gameboard->Board[pos.X][pos.Y]) {
        return 1;
    }
    else {
        return 0;
    }
}

int checkSetBoardRaw(Gameboard*gameboard, Vector2 pos) {
    if (gameboard->Board[pos.X][pos.Y]) {
        return 1;
    }
    else {
        return 0;
    }
}


void init_game(Gameboard*gameboard) {
    clearBoard(gameboard);
    srand(time(NULL));
}

Vector2 genRandom() {
    Vector2 pos = {rand()%3, rand()%3};
    return pos;
}

void setRandom(Gameboard*gameboard) {

    int timeout = 100;
    Vector2 randomPos = genRandom();
    int setBoardResult;

    do {
        randomPos = genRandom();
        setBoardResult = checkSetBoardRaw(gameboard, randomPos);
        timeout--;
    } while (setBoardResult == 1 && timeout > 0);

    if (setBoardResult != 1) {
        gameboard->Board[randomPos.X][randomPos.Y] = 1;
    }
    else {
        printf("Timed out");
    }
}

int checkBoardRemaining(Gameboard*gameboard) {
    int total = 0;
    for (int i = 0;i<3;i++) {
        total += gameboard->Board[i][0];
    }
    for (int i = 0;i<3;i++) {
        total += gameboard->Board[i][1];
    }
    for (int i = 0;i<3;i++) {
        total += gameboard->Board[i][2];
    }
    printf("%i\n", total);
    return total;
}

int AIselect(Gameboard*gameboard) {
    if (checkBoardRemaining(gameboard) < 9) {
        return 1;
    }
    else {
        return 0;
    }
}

int playerSelect(Gameboard*gameboard) {
    if (checkBoardRemaining(gameboard) < 9) {
        int input;
        printf("Type a number between 1 and 9");
        scanf("%i", &input);
        if (input < 1 || input > 9) {
            printf("Invalid input. Please enter a number between 1 and 9.\n");
            return 0;
        } else {
            Vector2 pos;
            pos.X = (input - 1) / 3;
            pos.Y = (input - 1) % 3;
            setBoard(gameboard, pos, 1);
            return 1;
        }
    }
}