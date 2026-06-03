#include <iostream>
#include <string>
#include <cstdlib>
const int COLS = 3;
const int ROWS = 3;
const int numOfShips = 3;

void printMatrix(int matrix[][COLS]);
void clearMatrix(int matrix[][COLS]);
void shipPosition(int matrix[][COLS]);
void getInput(int matrix[][COLS]);

int main()
{
    int matrix [ROWS][COLS];
    std::srand(std::time(nullptr));
    clearMatrix(matrix);
    shipPosition(matrix);

    getInput(matrix);
    printMatrix(matrix);
}

/**
 * @brief Initializes the array elements to 0
 * @param matrix[] holds the table of the ships and empty values
 */
void clearMatrix(int matrix[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

/**
 * @brief: print out the matrix
 * @param: matrix[] hold the table of the ship and empty values
 */
void printMatrix(int matrix[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * @brief: randomly assinged the ships into different position
 * @param matrix hold the position of the ships
 */
void shipPosition(int matrix[][COLS])
{
    int ships = 0;

    while (ships < numOfShips)
    {
        //this will create random positons for the ships
        int x = std::rand() % ROWS;
        int y = std::rand() % COLS;
        matrix[x][y] = 1;
        ships++;
    }
}

/**
 * @brief Gets input from the user for the guess of the ship positions
 * @param matrix
 */
void getInput(int matrix[][COLS])
{
    int ships = 0;
    int inputRows = 0, inputCols = 0;
    std::string YesNo = "";
    do
    {
        std::cout << "Please enter a position for your guess: " << std::endl;
        std::cin >> inputRows >> inputCols;
        if (matrix[inputRows][inputCols] == 1 && inputRows < ROWS && inputCols < COLS)
        {
            std::cout << "You got it!" << std::endl;
            matrix[inputRows][inputCols] = 2;
            ships++;
        }
        else
        {
            std::cout << "Try again! Do you want to quit(Y/N): ";
            std::cin >> YesNo;
            if (YesNo == "Y")
            {
                std::cout << "Thanks for playing! " << std::endl;
               return;
            }
        }
    }while (ships < numOfShips);
}
