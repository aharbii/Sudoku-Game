/******************************************************************************
 * FILE: main.c
 * DESCRIPTION:  Simple sudoku game program, in which it displays a start board
 *               and the user can enter row, col, and his value.
 *
 *               The game will end once the user completes all of the empty
 *               positions.
 *  _________           .___        __              ________
 * /   _____/ __ __   __| _/ ____  |  | __ __ __   /  _____/ _____     _____    ____
 * \_____  \ |  |  \ / __ | /  _ \ |  |/ /|  |  \ /   \  ___ \__  \   /     \ _/ __ \
 * /        \|  |  // /_/ |(  <_> )|    < |  |  / \    \_\  \ / __ \_|  Y Y  \  ___/
 * /_______  /|____/ \____ | \____/ |__|_ \|____/   \______  /(____  /|__|_|  / \___  >
 *       \/             \/             \/                \/      \/       \/      \/
 *
 * AUTHOR: Ahmed Harbi
 * DATE: March 2022
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "ui.h"
#include "brain.h"

int main()
{
    extern int sudoku_map[SUDOKU_LEN][SUDOKU_LEN];
    extern int validation_map[SUDOKU_LEN][SUDOKU_LEN];
    ui_splash_screen();
    ui_loading();
    brain_generate_values(sudoku_map);
    brain_save_start_map(sudoku_map, validation_map);
    while (brain_game_mointoring(sudoku_map) == GAME_IS_RUNNING)
    {
        ui_grid(sudoku_map);
        int row = 0;
        int col = 0;
        int user_ans = 0;
        ui_ask_for_input(sudoku_map, &row, &col, &user_ans);
        int user_answer_stats = brain_get_user_input(sudoku_map, validation_map, row, col, user_ans);
        if (user_answer_stats == INVALID_INPUT)
        {
            ui_invalid_position();
        }
    }
    if (brain_game_mointoring(sudoku_map) == USER_WIN)
    {
        ui_show_win_status();
    }
    else
    {
        ui_show_game_over();
    }
}