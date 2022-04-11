#include "ui.h"

void ui_splash_screen(void)
{
    printf("\n\n");
    printf("  _________           .___        __              ________\n /   _____/ __ __   __| _/ ____  |  | __ __ __   /  _____/ _____     _____    ____  \n \\_____  \\ |  |  \\ / __ | /  _ \\ |  |/ /|  |  \\ /   \\  ___ \\__  \\   /     \\ _/ __ \\ \n /        \\|  |  // /_/ |(  <_> )|    < |  |  / \\    \\_\\  \\ / __ \\_|  Y Y  \\  ___/ \n/_______  /|____/ \\____ | \\____/ |__|_ \\|____/   \\______  /(____  /|__|_|  / \\___  >\n        \\/             \\/             \\/                \\/      \\/       \\/      \\/ \n");
    printf("\n\n");
}

void ui_loading(void)
{
    printf("Please wait, the game is loading...\n");
}

void ui_grid(int sudoku_map[SUDOKU_LEN][SUDOKU_LEN])
{
    for (int i = 1; i <= SUDOKU_LEN; i++)
    {
        if (((i - 1) % 3) == 0)
        {
            printf("+-------+-------+-------+\n");
        }
        for (int j = 1; j <= SUDOKU_LEN; j++)
        {
            if (((j - 1) % 3) == 0)
            {
                printf("| ");
            }
            if (sudoku_map[i - 1][j - 1])
            {
                printf("%d ", sudoku_map[i - 1][j - 1]);
            }
            else
            {
                printf(". ");
            }
        }
        printf("|\n");
    }
    printf("+-------+-------+-------+\n");
}

void ui_ask_for_input(int sudoku_map[SUDOKU_LEN][SUDOKU_LEN], int *row_val, int *col_val, int *ans_val)
{
    printf("Enter row(1, 9), column(1, 9), value(1, 9):  ");
    int row = 0;
    int col = 0;
    int ans = 0;
    scanf("%d %d %d", &row, &col, &ans);
    *row_val = row - 1;
    *col_val = col - 1;
    *ans_val = ans;
}

void ui_show_win_status(void)
{
    printf("Congratulations, You Win!\n");
}

void ui_show_game_over(void)
{
    printf("You lose, GAME OVER!\n");
}

void ui_invalid_position(void)
{
    printf("You can't change this value, try again.\n");
}