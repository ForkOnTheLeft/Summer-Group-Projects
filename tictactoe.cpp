#include <iostream>
#include <string>

const int ROWS = 3;
const int COLS = 3;

void printMatrix(char tictac[][COLS], int ROWS);

int getInput(char tictac[][COLS], int ROWS, int &count);

void assigning(char tictac[][COLS], int ROWS, int &num, char &player);

void toggle(char &player);

bool win(char tictac[][COLS], int ROWS);

int main()
{
    char player = 'X';
    int num = 0;

    bool found;
    char tictac[ROWS][COLS] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int count = 0;
    while (true)
    {
        printMatrix(tictac, ROWS);
        std::cout << "Player " << player << "'s turn" << std::endl;
        num = getInput(tictac, ROWS, count);
        assigning(tictac, ROWS, num, player);
        found = win(tictac, ROWS);

        //If win condition is found
        if (found)
        {
            printMatrix(tictac, ROWS);
            std::cout << "The winner is " << player << " !!" << std::endl;
            break;
        }

        //Draw condition
        if (count == 9)
        {
            printMatrix(tictac, ROWS);
            std::cout << "Game is a draw." << std::endl;
            break;
        }
        toggle(player);
    }
    return 0;
}

/**
 * @brief prints out the matrix with formatted lines for Tic-Tac-Toe
 * @param tictac Matrix for the Tic-Tac-Toe
 * @param ROWS Numer of rows in the matrix
 */
void printMatrix(char tictac[][COLS], int ROWS)
{
    std::cout << "-----------" << std::endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            std::cout << tictac[i][j] << " | ";
        }
        std::cout << std::endl;
        std::cout << "-----------" << std::endl;
    }
}

/**
 * @brief Prompt the user to input
 *
 * @param tictac Matrix for the Tic-Tac-Toe
 * @param ROWS Number of rows in the matrix
 */
int getInput(char tictac[][COLS], int ROWS, int &count)
{
    int num;
    // Validate the input
    do
    {
        std::cout << "Please enter the number you would like to replace: ";
        std::cin >> num;
        count++;
        //checking(tictac, ROWS, num);
    } while (num < 0 || num > 9);
    return num;
}

/**
 * @brief Assign the position of current player
 *
 * @param tictac hold the number of position in the Tic-Tac-Toe table
 * @param ROWS The number of rows in the matrix
 * @param num The position of the current player
 * @param player represent X and O
 */
void assigning(char tictac[][COLS], int ROWS, int &num, char &player)
{
    int row = (num - 1) / 3;
    int col = (num - 1) % 3;
    if (tictac[row][col] != 'X' && tictac[row][col] != 'O')
    {
        tictac[row][col] = player;
    }else
    {
        std::cout << "Spot already assigned. Try again" << std::endl;
    }
}

/**
 * @brief Switches the current player between X and O
 *
 * @param player Reference to the current player character
 */
void toggle(char &player)
{
    if (player == 'X')
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }
}

/**
 * @brief Checks if there is a winner in the Tic-Tac-Toe
 *
 * @param tictac hold the number of position in the Tic-Tac-Toe table
 * @param ROWS Number of rows in the matrix
 * @return true if either player has won, false otherwise
 */
bool win(char tictac[][COLS], int ROWS)
{
    // Checking rows
    for (int i = 0; i < ROWS; i++)
    {
        if ((tictac[i][0] == 'X' && tictac[i][1] == 'X' && tictac[i][2] == 'X' )||
            (tictac[i][0] == 'O' && tictac[i][1] == 'O' && tictac[i][2] == 'O'))
        {

            return true;
        }
    }

    // Checking columns
    for (int i = 0; i < ROWS; i++)
    {
        if ((tictac[0][i] == 'X' && tictac[1][i] == 'X' && tictac[2][i] == 'X' )||
            (tictac[0][i] == 'O' && tictac[1][i] == 'O' && tictac[2][i] == 'O'))
        {
            return true;
        }
    }

    // Checking diagonals
    if ((tictac[0][0] == 'X' && tictac[1][1] == 'X' && tictac[2][2] == 'X' )||
            (tictac[0][0] == 'O' && tictac[1][1] == 'O' && tictac[2][2] == 'O'))
    {
        return true;
    }

    // Checking diagonals
    if ((tictac[2][0] == 'X' && tictac[1][1] == 'X' && tictac[0][2] == 'X' )||
            (tictac[2][0] == 'O' && tictac[1][1] == 'O' && tictac[0][2] == 'O'))
    {
        return true;
    }
    return false;
}
