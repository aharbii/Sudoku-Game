/******************************************************************************
 * FILE: ui.h
 * DESCRIPTION:  Header file includes documentation and function declarations
 *               for the functions which are implemented in ui.c file to handle
 *               the user interface for the game.
 *
 * AUTHOR: Ahmed Harbi
 * DATE: March 2022
 *****************************************************************************/

#ifndef _UI_H_
#define _UI_H_

#include <stdio.h>
#include <stdlib.h>

#define SUDOKU_LEN 9

/******************************************************************************
 * FUNCTION: ui_splash_screen
 * DESCRIPTION:  Displays the game logo when the game starts.
 *
 *  _________           .___        __              ________
 * /   _____/ __ __   __| _/ ____  |  | __ __ __   /  _____/ _____     _____    ____
 * \_____  \ |  |  \ / __ | /  _ \ |  |/ /|  |  \ /   \  ___ \__  \   /     \ _/ __ \
 * /        \|  |  // /_/ |(  <_> )|    < |  |  / \    \_\  \ / __ \_|  Y Y  \  ___/
 * /_______  /|____/ \____ | \____/ |__|_ \|____/   \______  /(____  /|__|_|  / \___  >
 *       \/             \/             \/                \/      \/       \/      \/
 *****************************************************************************/

void ui_splash_screen(void);

/******************************************************************************
 * FUNCTION: ui_gird
 * DESCRIPTION:  Displays the game board with dots in the places which the user
 *               can enters his answers, the grid is mapped from 1 to 9
 *               vertically and horizontally.
 *
 *                    +-------+-------+-------+
 *                    | 6 . . | 3 . 2 | . . . |
 *                    | . 4 . | . . . | . 1 . |
 *                    | . . . | . . . | . . . |
 *                    +-------+-------+-------+
 *                    | 7 . 2 | 6 . . | . . . |
 *                    | . . . | . . . | . 5 4 |
 *                    | 3 . . | . . . | . . . |
 *                    +-------+-------+-------+
 *                    | . 8 . | 1 5 . | . . . |
 *                    | . . . | . 4 . | 2 . . |
 *                    | . . . | . . . | 7 . . |
 *                    +-------+-------+-------+
 *
 * INPUTS:
 *      sudoko_map: a 2D array of integers represents the values on the board.
 *****************************************************************************/

void ui_grid(int sudoku_map[SUDOKU_LEN][SUDOKU_LEN]);

/******************************************************************************
 * FUNCTION: ui_ask_for_input
 * DESCRIPTION:  A function receives prompt input from the user represents
 *               his answer in format of (row, column, answer).
 * INPUTS:
 *      sudoko_map: a 2D array of integers represents the values on the board.
 *      row_val: a pointer to the variable which represents the row (0-indexed).
 *      col_val: a pointer to the variable which represents the column (0-indexed).
 *      ans_val: a pointer to the variable which represents users answer.
 *****************************************************************************/

void ui_ask_for_input(int sudoku_map[SUDOKU_LEN][SUDOKU_LEN], int *row_val, int *col_val, int *ans_val);

/******************************************************************************
 * FUNCTION: ui_show_win_status
 * DESCRIPTION:  Displays a message for winners.
 *****************************************************************************/

void ui_show_win_status(void);

/******************************************************************************
 * FUNCTION: ui_show_game_over
 * DESCRIPTION:  Displays a for the losers.
 *****************************************************************************/

void ui_show_game_over(void);

/******************************************************************************
 * FUNCTION: ui_show_game_over
 * DESCRIPTION:  Displays a message in case the users enters Invalid value,
 *               for row, column, out-of-range answer, or tried to change a
 *               generated value.
 *****************************************************************************/

void ui_invalid_position(void);

/******************************************************************************
 * FUNCTION: ui_show_game_over
 * DESCRIPTION:  Displays the loading message.
 *****************************************************************************/

void ui_loading(void);

#endif /* _UI_H_ */