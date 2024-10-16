#include<stdio.h>
#include<math.h>
#include<time.h>

#include<stdlib.h>
#define boardsize 3

typedef struct Vector2 {
     int X;
     int Y;
}Vector2;

typedef struct Gameboard {
     int Board[3][3];
}Gameboard;

int checkForWinner(Gameboard*gameboard) {
for (int index = 0;index < 3;index++) {
    printf("1:%i 2:%i 3:%i\n", gameboard->Board[index][0], gameboard->Board[index][1], gameboard->Board[index][2]);
    if (gameboard->Board[index][0] == 1 && gameboard->Board[index][1] == 1 && gameboard->Board[index][2] == 1) {
        return 1;
    }
}
return 0;
}

int checkBoardRemaining(Gameboard*gameboard) {
    int total = 0;

    for (int i = 0;i<3;i++) {
        for (int i2 = 0;i2<3;i2++) {
            // printf("Value at (%i, %i) is %i\n", i,i2 , gameboard->Board[i][i2]);
            if (gameboard->Board[i][i2]) {
                total += 1;
            }
        }
    }
    printf("%i\n", total);
    return total;
}

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
    printf("\r");
    for (int HORIZONTAL = 0;HORIZONTAL<3;HORIZONTAL++) {
        for (int VERTICAL = 0;VERTICAL<3;VERTICAL++) {
            if (gameboard->Board[HORIZONTAL][VERTICAL] == 1) {
                printf("#");
            }
            else if (gameboard->Board[HORIZONTAL][VERTICAL] == 2) {
                printf("X");
            }
            else {
                printf("O");
            }
        }
        printf("\n");
    }
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

void endGame(Gameboard*gameboard, int *exitVal) {
    printf("The game has ended successfully");
    *exitVal = 1;
    exit(0);
}

void initGame(Gameboard*gameboard) {
    clearBoard(gameboard);
    srand(time(NULL));
}

Vector2 genRandom() {
    Vector2 pos = {rand()%3, rand()%3};
    return pos;
}

void setRandom(Gameboard*gameboard, int val) {

    int timeout = 100;
    Vector2 randomPos = genRandom();
    int setBoardResult;

    do {
        randomPos = genRandom();
        setBoardResult = checkSetBoardRaw(gameboard, randomPos);
        timeout--;
        // printf("Running lopp");
    } while (checkBoardRemaining(gameboard) < 9 && setBoardResult == 1 && timeout > 0);

    // printf("AI choose %i %i\n", randomPos.X, randomPos.Y);

    if (setBoardResult != 1) {
        gameboard->Board[randomPos.X][randomPos.Y] = val;
    }
    else {
        printf("Timed out\n");
    }
}

int AIselect(Gameboard*gameboard) {
    if (checkBoardRemaining(gameboard) <= 9) {
        printf("AI is choosing a random number\n");
        setRandom(gameboard, 2);
        return 1;
    }
    else {
        return 0;
    }
}

void playerSelect(Gameboard*gameboard) {
    if (checkBoardRemaining(gameboard) < 9) {
        int input1;
        int input2;
        start:
        printf("Type a number from 1 to 3 where the pawn should be placed horizontally. |\n");
        scanf(" %i", &input1);
        while (input1>3||input1<1) {
            printf("Invalid input. Please enter a number between 1 and 3 ?%i .\n", input1);
            scanf(" %i", &input1);
        }
        printf("Type another number between 1 and 3  where the pawn should be placed vertically. -\n");
        scanf("%i", &input2);
        while (input2>3 || input2<1) {
            printf("Invalid input. Please enter a number between 1 and 3.\n");
            scanf(" %i", &input2);
            // return 0;
        } 
            Vector2 check;
            check.X = input1;
            check.Y = input2;
            if (readBoard(gameboard, check)) {
                printf("This posistion already has a pawn\n");
                goto start;
            }
            else {
                Vector2 pos;
                pos.X = input1;
                pos.Y = input2;
                setBoard(gameboard, pos, 1);
                // return 1;
            }
    }
}
