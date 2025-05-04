#include <iostream>

int counter = 0;
const int size_x = 5;
const short size_y = 5;
char game_place[size_x][size_y];

void create_place() // finished
{
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            if (i == 0 || j == 0 || i == size_x - 1 || j == size_y - 1)
            {
                game_place[i][j] = '@';
            }
            else
            {
                game_place[i][j] = ' ';
            }
        }
    }
}

void check_place() // finished
{
    for (int y = 0; y < size_y; y++)
    {
        for (int x = 0; x < size_x; x++)
        {
            std::cout << game_place[x][y];
        }
        std::cout << "\n";
    }
}

void block_break() // finished
{
    for (int i = size_x - 2; i > 0; i--)
    {
        for (int j = size_y - 2; j > 1; j--)
        {
            game_place[i][j] = game_place[i][j - 1];
        }
    }
}

bool block_fall() // finished
{
    char hash_tag = '#';
    int rand_index = rand() % (size_x - 2) + 1;

    // game over

    for (int i = 1; i < size_x; i++)
    {
        if (game_place[i][1] == '#')
        {
            return false;
        }
    }

    // game loop

    for (int y = 1; y < size_y - 1; y++)
    {
        for (int i = 0; i < 99999; i++)
            for (int j = 0; j < 6999; j++)
                ;

        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

        if (y > 1)
            game_place[rand_index][y - 1] = ' ';

        if (game_place[rand_index][y + 1] == '#')
        {
            game_place[rand_index][y] = hash_tag;
            check_place();
            break;
        }
        else
        {
            game_place[rand_index][y] = hash_tag;
            check_place();
        }
    }

    counter++;

    // check block break

    for (int x = 1; x < size_x - 1; x++)
    {
        if (game_place[x][size_y - 2] != '#')
            return true;
    }

    counter += size_x - 2;

    block_break();

    return true;
}

void start() // finished
{
    create_place();

    while (true)
    {
        if (!(block_fall()))
        {
            std::cout << "\n\nGame over! Counts: " << counter;
            break;
        }
    }
}

int main()
{
    srand(time(NULL));
    start();

    return 0;
}