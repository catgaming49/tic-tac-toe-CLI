#ifndef GAMEUTILS_H
#define boardsize 3

typedef struct Vector2 {
     int X;
     int Y;
}Vector2;

typedef struct Gameboard {
     int Board[3][3];
}Gameboard;

/**
 * @brief Constricts a value to a set range. separated from processVector() for potential future use
 * 
 * @param num 
 * @return int 
 */
int constrict(int num);

/**
 * @brief Sets a value between 0-2 to a value between 0-3 to account for arrays
 * 
 * @param pos The position to process 
 */
void processVector(Vector2*pos);

/**
 * @brief Clear the entire board
 * 
 * @param gameboard A pointer to the gameboard
 */
void clearBoard(Gameboard*gameboard);

/**
 * @brief Sets the value at the position
 * 
 * @param gameboard A pointer to the gameboard
 * @param pos The position to set the value at
 * @param val The value to set the specified location at
 */
void setBoard(Gameboard*gameboard, Vector2 pos, int val);



void setBoardRaw(Gameboard*gameboard, Vector2 pos, int val);

/**
 * @brief Reads the value at the position
 * 
 * @param gameboard A pointer to the gameboard
 * @param pos The position to read the value at
 * @return int 
 */
int readBoard(Gameboard*gameboard, Vector2 pos);

/**
 * @brief renders the board once
 * 
 * @param gameboard A pointer to the gameboard
 */
void renderBoard(Gameboard*gameboard);

/**
 * @brief Set a Random board position to 1
 * 
 * @param gameboard A pointer to the gameboard
 */
void setRandom(Gameboard*gameboard);

/**
 * @brief Check if the positions is already set, could use readBoard but this function explicitly returns 0 or 1
 * 
 * @param gameboard A pointer to the gameboard
 * @return int 
 */
int checkSetBoard(Gameboard*gameboard, Vector2 pos);

/**
 * @brief 
 * 
 */
void genRandom();

int checkSetBoardRaw(Gameboard*gameboard, Vector2 pos);

void init_game(Gameboard*gameboard);

/**
 * @brief 
 * 
 * @return int 
 */
int checkBoardRemaining(Gameboard*gameboard);

/**
 * @brief 
 * 
 */
int AIselect(Gameboard*gameboard);

/**
 * @brief 
 * 
 */
int playerSelect(Gameboard*gameboard);

#endif