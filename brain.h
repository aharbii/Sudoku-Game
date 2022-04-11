/******************************************************************************
 * FILE: brain.h
 * DESCRIPTION:  Header file includes documentation and function declarations
 *               for the functions which are implemented in brain.c file which
 *               handle the brain of the game.
 *
 * AUTHOR: Ahmed Harbi
 * DATE: March 2022
 *****************************************************************************/

#ifndef _BRAIN_H_
#define _BRAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUDOKU_LEN 9
#define INVALID_INPUT 0
#define VALID_INPUT 1
#define GAME_IS_RUNNING 0
#define USER_LOSE -1
#define USER_WIN 1
#define START_VALUES 30
#define EMPTY_POSITION 0
#define CELL_STEP 3
#define HASH_MARK 1
#define POSITIONS 81
#define DATABASE_LEN 95

/******************************************************************************
 * FUNCTION: brain_validate_values
 * DESCRIPTION:  Checks the values on the board while during the game to
 *               determine user's game result.
 *
 * NOTE: Can be used to generate the board regrads the database, but it takes
 *       too much time; due to the wide range of probabilities.
 *
 * INPUT:
 *      sudoko_map: a 2D array of integers represents the values on the board.
 * RETURN: 
 *      INVALID_INPUT: declares that the written values, are not a valid sudoku
 *                     game.
 *      VALID_INPUT: declares that the written values, are a valid sudoku game. 
 *****************************************************************************/

int brain_validate_values(int sudoku_map[SUDOKU_LEN][SUDOKU_LEN]);

/******************************************************************************
 * FUNCTION: brain_generate_values
 * DESCRIPTION:  Generates the board before starting the game.
 *
 * INPUT:
 *      sudoko_map: a 2D array of integers represents the values on the board.
 *****************************************************************************/

void brain_generate_values(int sudoku_map[SUDOKU_LEN][SUDOKU_LEN]);

/******************************************************************************
 * FUNCTION: brain_save_start_map
 * DESCRIPTION:  Save the start values of the board, used to prevent the user, 
 *               changing the generated values.
 * INPUT:
 *      sudoko_map: a 2D array of integers represents the values on the board.
 *      validation_map: a 2D array of integers which used to save the starting
 *                      data.
 *****************************************************************************/

void brain_save_start_map(int sudoku_map[SUDOKU_LEN][SUDOKU_LEN], int validation_map[SUDOKU_LEN][SUDOKU_LEN]);

/******************************************************************************
 * FUNCTION: brain_game_monitoring
 * DESCRIPTION:  Monintoring the game status after each single user input,
 *               to determine if the game is still running and has possible
 *               changes or this is the last move.
 * INPUT:
 *      sudoko_map: a 2D array of integers represents the values on the board.
 * RETURN:
 *      GAME_IS_RUNNING: indicates that the game still has possible moves.
 *      USER_WIN: informs the program that the user has won the game.
 *      USER_LOSE: informs the program that the user lose the game.
 *****************************************************************************/

int brain_game_mointoring(int sudoku_map[SUDOKU_LEN][SUDOKU_LEN]);

/******************************************************************************
 * FUNCTION: brain_get_user_input
 * DESCRIPTION:  Checks the user input in each round, and informs the program,
 *               if the user has entered an invalid input for the row, column
 *               value, or even tried to manipulate a program generated value.
 * INPUT:
 *      sudoko_map: a 2D array of integers represents the values on the board.
 *      validation_map: a 2D array of integers represents the values which
 *                      have been generated from the program at the start of
 *                      game.
 *      row: an integer received from the user (0-indexed).
 *      col: an integer received from the user (0-indexed).
 *      ans: and integer received from the user.
 * RETURN:
 *      INVALID_INPUT: declares that the written values, are not a valid sudoku
 *                     game.
 *      VALID_INPUT: declares that the written values, are a valid sudoku game.
 *****************************************************************************/

int brain_get_user_input(int sudoku_map[SUDOKU_LEN][SUDOKU_LEN], int validation_map[SUDOKU_LEN][SUDOKU_LEN], int row, int col, int ans);

#endif /* _BRAIN_H_ */