#include <iostream>
#include <conio.h>
#include <cstdlib> // For random number
#include <ctime> // time
#include <windows.h>

// Map Dimension
const int width = 20;
const int length = 20;
const int tail_size = 100;

// Global Variable Declaration
int headX, headY;    // Snake head position
int fruitX, fruitY;  // Fruit position
bool gameOver;       // Indicates if the game has ended
int score = 0;       // Score eating fruit
int tailX[tail_size], tailY[tail_size];    // Arrays store the length of the snake's tail
int tailLength = 0;

// Enum representing movement direction
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

// Function Declaration
void initialize();
void setUp();
void input();
void logic();

int main()
{
    std::srand(std::time(nullptr));
    initialize();

    while (!gameOver)
    {
        setUp();
        input();
        logic();
        Sleep(150);
    }

    return 0;
}

void initialize()
{
    gameOver = false;
    dir = STOP;
    headX = width / 2;
    headY = length / 2;
    score = 0;
    tailLength = 0;

    fruitX = std::rand() % width;
    fruitY = std::rand() % length;
}

/**
 * @brief: creates the map, spawns the snake and the fruit
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
            else if (j == width - 1)
            {
                std::cout << "#";
            }
            else if ( i == headY && j == headX)  //spawn snake's head
            {
                 std::cout << "O";
            }
            else if ( i == fruitY && j == fruitX) //spawn the fruit
            {
                 std::cout << "F";
            }

            else
            {
                bool found = false;
                for ( int k = 0; k < tailLength; k++) // spawn snake's tail
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        std::cout << "o";
                        found = true;
                    }
                }
                //blank spaces if no tail
                if (!found)
                {
                    std::cout << " ";
                }
            }

        }
        std::cout << std::endl;
    }

    // Bottom Wall
    for (int i = 0; i < width; i++)
    {
        std::cout << "#";
    }

    std::cout << std::endl;

    std::cout << "Score: " << score << std::endl;
}

/*
 * @brief takes keyboard input from user to move the snake with wasd. any other key will exit the game
 */
void input()
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

/*
 * @brief logic of the game for movement
 */
void logic()
{
    // Swapping tail positions
    int swappingX = tailX[0];
    int swappingY = tailY[0];
    int swapping2X, swapping2Y;

    tailX[0] = headX;
    tailY[0] = headY;

    for (int i = 1; i < tailLength; i++)
    {
        swapping2X = tailX[i];
        swapping2Y = tailY[i];

        tailX[i] = swappingX;
        tailY[i] = swappingY;

        swappingX = swapping2X;
        swappingY = swapping2Y;
    }

    // Moving snake head with wasd
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

    // Colliding wall = gameover
    if ( headX < 0 || headX >= width || headY < 0 || headY >= length)
    {
        gameOver = true;
    }

    // Touching itself = gameover
    for (int i = 0; i < tailLength; i++)
    {
        if (headX == tailX[i] && headY == tailY[i])
        {
            gameOver = true;

        }
    }

    // Eating fruit = longer tail length
    if (headX == fruitX && headY == fruitY)
    {
        score += 10;
        fruitX = std::rand() % width;
        fruitY = std::rand() % length;
        tailLength++;
    }
}
