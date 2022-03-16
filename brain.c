#include "brain.h"

int brain_validate_values(int sudoku_map[SUDOKU_LEN][SUDOKU_LEN])
{
    int *hash_table = (int *)calloc(SUDOKU_LEN, sizeof(int));
    for (int i = 0; i < SUDOKU_LEN; i++)
    {
        for (int j = 0; j < SUDOKU_LEN; j++)
        {
            if (sudoku_map[i][j] != EMPTY_POSITION)
            {
                hash_table[sudoku_map[i][j] - 1] += HASH_MARK;
            }
        }

        for (int k = 0; k < SUDOKU_LEN; k++)
        {
            if (hash_table[k] > HASH_MARK)
            {
                return INVALID_INPUT;
            }
            hash_table[k] = EMPTY_POSITION;
        }
    }
    for (int i = 0; i < SUDOKU_LEN; i++)
    {
        for (int j = 0; j < SUDOKU_LEN; j++)
        {
            if (sudoku_map[j][i] != EMPTY_POSITION)
            {
                hash_table[sudoku_map[j][i] - 1] += HASH_MARK;
            }
        }

        for (int k = 0; k < SUDOKU_LEN; k++)
        {
            if (hash_table[k] > HASH_MARK)
            {
                return 0;
            }
            hash_table[k] = 0;
        }
    }
    for (int i = 0; i <= SUDOKU_LEN - CELL_STEP; i += CELL_STEP)
    {
        for (int j = 0; j <= SUDOKU_LEN - CELL_STEP; j += CELL_STEP)
        {
            for (int x = 0; x < CELL_STEP; x++)
            {
                for (int y = 0; y < CELL_STEP; y++)
                {
                    if (sudoku_map[i + x][j + y] != EMPTY_POSITION)
                    {
                        hash_table[sudoku_map[i + x][j + y] - HASH_MARK] += HASH_MARK;
                    }
                }
            }
            for (int k = 0; k < SUDOKU_LEN; k++)
            {
                if (hash_table[k] > HASH_MARK)
                {
                    return INVALID_INPUT;
                }
                hash_table[k] = EMPTY_POSITION;
            }
        }
    }
    free(hash_table);
    return VALID_INPUT;
}

void brain_generate_values(int sudoku_map[SUDOKU_LEN][SUDOKU_LEN])
{
    srand(time(0));
    int chosen_board = rand() % DATABASE_LEN;
    int row = 0;
    int col = 0;
    int k = 0;
    extern char *database[DATABASE_LEN];
    for (int i = 0; i < SUDOKU_LEN; i++)
    {
        for (int j = 0; j < SUDOKU_LEN; j++)
        {
            if (database[chosen_board][k] == '.')
            {
                sudoku_map[i][j] = EMPTY_POSITION;
            }
            else
            {
                sudoku_map[i][j] = database[chosen_board][k] - '0';
            }
            k++;
        }
        
    }
    
}

/* Cancelled */

/*
void brain_generate_values(int sudoku_map[SUDOKU_LEN][SUDOKU_LEN])
{
    srand(time(0));
    int hidden_values = POSITIONS - START_VALUES;

    while (brain_game_mointoring(sudoku_map) == GAME_IS_RUNNING)
    {
        int row = rand() % SUDOKU_LEN;
        int col = rand() % SUDOKU_LEN;
        int value = (rand() % SUDOKU_LEN) + 1;
        if (sudoku_map[row][col] == EMPTY_POSITION)
        {
            sudoku_map[row][col] = value;
            if (brain_validate_values(sudoku_map) == VALID_INPUT)
            {
                col++;
                if (col == SUDOKU_LEN)
                {
                    col = 0;
                    row++;
                }

            }
            else
            {
                sudoku_map[row][col] = EMPTY_POSITION;
            }
        }
    }
    while (hidden_values)
    {
        int row = rand() % SUDOKU_LEN;
        int col = rand() % SUDOKU_LEN;
        if (sudoku_map[row][col] != EMPTY_POSITION)
        {
            sudoku_map[row][col] = EMPTY_POSITION;
            hidden_values -= 1;
        }
    }

}
*/

void brain_save_start_map(int sudoku_map[SUDOKU_LEN][SUDOKU_LEN], int validation_map[SUDOKU_LEN][SUDOKU_LEN])
{
    for (int i = 0; i < SUDOKU_LEN; i++)
    {
        for (int j = 0; j < SUDOKU_LEN; j++)
        {
            validation_map[i][j] = sudoku_map[i][j];
        }
    }
}

int brain_get_user_input(int sudoku_map[SUDOKU_LEN][SUDOKU_LEN], int validation_map[SUDOKU_LEN][SUDOKU_LEN], int row, int col, int ans)
{
    if (row >= SUDOKU_LEN || col >= SUDOKU_LEN)
    {
        return INVALID_INPUT;
    }
    
    if (ans > SUDOKU_LEN)
    {
        return INVALID_INPUT;
    }
    
    if (validation_map[row][col])
    {
        return INVALID_INPUT;
    }
    sudoku_map[row][col] = ans;
    return VALID_INPUT;
}

int brain_game_mointoring(int sudoku_map[SUDOKU_LEN][SUDOKU_LEN])
{
    for (int i = 0; i < SUDOKU_LEN; i++)
    {
        for (int j = 0; j < SUDOKU_LEN; j++)
        {
            if (sudoku_map[i][j] == EMPTY_POSITION)
            {
                return GAME_IS_RUNNING;
            }
        }
    }
    if (brain_validate_values(sudoku_map) == VALID_INPUT)
    {
        return USER_WIN;
    }
    return USER_LOSE;
}