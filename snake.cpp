#include <iostream>
#include <conio.h>
#include <cstdlib> // For random number
#include <ctime> // time

// Map Dimension
const int width = 20;
const int length = 20;

// Variable Declaration
int headX, headY;    // Snake head position
int fruitX, fruitY;  // Fruit position
bool gameOver;       // Indicates if the game has ended

// Enum representing movement direction
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

// Function Declaration
void initialize();
void setUp();
void Input();
void logic();

int main()
{
    gameOver = false;
    dir = STOP;
    std::srand(std::time(nullptr));
    initialize();
    setUp();

    while (!gameOver)
    {
        Input();
        logic();
    }
    return 0;
}

void initialize()
{
    gameOver = false;

    headX = width / 2;
    headY = length / 2;

    fruitX = std::rand() % width;
    fruitY = std::rand() % length;

}

/**
 * @brief: create the map, spawn the snake, and spam the fruit
 */
void setUp()
{
    system("cls");
     // Top wall
    for (int i = 0; i < width; i++)
    {
        std::cout << "#";
    }
    std::cout << std::endl;

    // Left and Right Walls
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Left wall
            if (j == 0)
            {
                std::cout << "#";
            }
            // Right wall
            if (j == width - 1)
            {
                std::cout << "#";
            }
            if ( i == headY && j == headX)  //spawn snake's head
             {
                 std::cout << "O";
             }
            else if ( i == fruitY && j == fruitX) //spam the fruit
            {
                 std::cout << "F";
                }

            else
            {
                std::cout << " ";
            }

        }
        std::cout << std::endl;
    }

    // Bottom Wall
    for (int i = 0; i < width; i++)
    {
        std::cout << "#";
    }
}

/*
 * @brief keyboard input
 */
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            default:
                std::cout << "Game over!" << std::endl;
                gameOver = true;
                break;
        }
    }
}

void logic()
{
    switch (dir)
    {
        case LEFT:
            headX--;
            break;
        case RIGHT:
            headX++;
            break;
        case UP:
            headY--;
            break;
        case DOWN:
            headY++;
            break;
        default:
            break;
    }

}
