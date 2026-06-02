#include <iostream>
#include <string>

const int ROWS = 3;
const int COLS = 3;

void printMatrix (char tictac[][COLS], int ROWS);
int getInput (char tictac[][COLS], int ROWS);
void checking (char tictac[][COLS], int ROWS, int &num);

int main(){
    int num = 0;
    char tictac[ROWS][COLS] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    printMatrix(tictac, ROWS);
    num = getInput (tictac, ROWS);
    return 0;
}

/**
 * @brief prints out the matrix with formatted lines for tictactoe
 * @param tictac Matrix for the tic tac
 * @param ROWS Numer of rows in the matrix
 */
void printMatrix (char tictac[][COLS], int ROWS)
{
    std::cout << "-----------" <<std::endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            std::cout << tictac[i][j] << " | ";
        }
        std::cout << std::endl;
        std::cout << "-----------" <<std::endl;
    }
}

/**
 * @brief Prompt the user to input
 *
 * @param tictac Matrix for the tic tac
 * @param ROWS Number of rows in the matrix
 */
int getInput (char tictac[][COLS], int ROWS)
{
    std::string input = "";
    int num;
    std::string player = "X";
    // Validate the input
    do
    {
        std::cout << "Please enter the number you would like to replace: ";
        std::cin >> input;
        // Convert char to integer for the range verification
        num = std::stoi(input);
        //checking(tictac, ROWS, num);
    } while ( num < 0 || num > 9 );
    return num;
}

/**
 * @brief check is space is already used for X or O
 * @param tictac
 * @param ROWS
 * @param num
 */
void checking (char tictac[][COLS], int ROWS, int &num)
{
    int rowIndex, colIndex;
    if (num == 1){
        rowIndex = 0;
        colIndex = 0;
    }
    else if (num == 2){
        rowIndex = 0;
        colIndex = 1;
    }
    else if (num == 3){
        rowIndex = 0;
        colIndex = 2;
    }
    else if (num == 4){
        rowIndex = 1;
        colIndex = 0;
    }
    else if (num == 5){
        rowIndex = 1;
        colIndex = 1;
    }
    else if (num == 6){
        rowIndex = 1;
        colIndex = 2;
    }
    else if (num == 7){
        rowIndex = 2;
        colIndex = 0;
    }
    else if (num == 8){
        rowIndex = 2;
        colIndex = 1;
    }
    else if (num == 9){
        rowIndex = 2;
        colIndex = 2;
    }
    while (tictac [rowIndex][colIndex] == 'X' || tictac [rowIndex][colIndex] == 'x' || tictac [rowIndex][colIndex] == 'O' || tictac [rowIndex][colIndex] == 'o' );
    // Return boolean false
}


/* Draft
while (true) {
     std::cout << "Enter a number between 1 and 9: ";
     int input;
     std::cin >> input ;
     if (choice < 1 || choice > 9){
         std::cout << "Try again";
         continue;
     }
     if (!checking){
         continue;
     }

 */