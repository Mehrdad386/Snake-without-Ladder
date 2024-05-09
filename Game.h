#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <array>

class Snake
{

public:
    Snake(int head, int tail)
    {

        setHead(head);
        setTail(tail);
    }

    Snake()
    {

        head = 0;
        tail = 0;
    }

    int getHead() { return head; }

    int getTail() { return tail; }

    void setTail(int tail) { this->tail = tail; }

    void setHead(int head) { this->head = head; }

private:
    int head; // to hold head of the snake position
    int tail; // to hold tail of the snake position
};

class Map
{

public:
    int getSize() { return size; }

    void setSize(int size) { this->size = size; }

private:
    int size;
};

class Player
{

public:
    std::string getName() { return name; }
    int getBite() { return bite; }
    int getPosition() { return position; }

    void setName(std::string name) { this->name = name; }
    void setBite(int bite) { this->bite = bite; }
    void addBite() { bite++; } // to add one to the number of bites
    void setPosition(int position) { this->position = position; }
    void addToPosition(int roll) { position += roll; }

    // to roll dice
    std::array<int, 2> roll()
    {

        std::array<int, 2> roll;
        roll[0] = rand() % 6 + 1;
        roll[1] = 0;

        if (roll[0] == 6)
            roll[1] += rand() % 6 + 1;

        return roll;
    }

private:
    int position = 1;
    std::string name;
    int bite = 0; // to hold the number of snake's bites
};

class Game
{

public:
    // to insert a random snake
    void randomSnake()
    {

        Snake snake;
        int randomHead = rand() % map.getSize() + 1;
        int randomTail = rand() % map.getSize() + 1;
        snake.setHead(randomHead);
        snake.setTail(randomTail);
        snakes.push_back(snake);
    }

    // to get inputs from user
    void InputData()
    {

        int size;
        std::cin >> size;
        map.setSize(size);

        Player player;
        std::string name;

        for (int i{}; i < playersNumber; i++)
        {

            std::cin >> name;
            player.setName(name);
            players.push_back(player);
        }

        std::cin >> snakesNumber;

        Snake snake;
        int position;

        for (int i{}; i < snakesNumber; i++)
        {

            std::cin >> position;
            snake.setHead(position);

            std::cin >> position;
            snake.setTail(position);

            snakes.push_back(snake);
        }
    }

    void move(int n)
    {

        bool flag = false;
        // first player rolling
        std::array<int, 2> roll = players[n].roll();

        if (players[n].getPosition() + roll[0] > map.getSize() || players[n].getPosition() + roll[0]+roll[1] > map.getSize()){
            if(players[n].getPosition() + roll[0] < map.getSize()){
                std::cout << players[n].getName() << " rolled " << roll[1] << " and is on " << players[n].getPosition() << std::endl;
            }
            if(players[n].getPosition() + roll[1] < map.getSize() && roll[1]>0){
                std::cout << players[n].getName() << " rolled " << roll[1] << " and is on " << players[n].getPosition() << std::endl;
            }
            else
                std::cout << players[n].getName() << " can't move\n";
        }
        else
        {
            if (roll[1] == 0)
            {
                players[n].addToPosition(roll[0]);
                std::cout << players[n].getName() << " rolled " << roll[0] << " and is on " << players[n].getPosition() << std::endl;
            }
            else
            {
                players[n].addToPosition(roll[0]);
                players[n].addToPosition(roll[1]);
                std::cout << players[n].getName() << " rolled " << roll[0] << " then " << roll[1] << " and is on " << players[n].getPosition() << std::endl;
            }

            for (int i = 0; i < snakesNumber; i++)
            {

                if (snakes[i].getHead() == players[n].getPosition())
                {

                    flag = true;
                    players[n].setPosition(snakes[i].getTail());
                    players[n].addBite();
                    break;
                }
            }
            if (flag)
            {
                std::cout << players[n].getName() << " bited and now is on: " << players[n].getPosition() << std::endl;
                flag = false;
            }
        }
    }

    // to run game
    void run()
    {

        InputData();

        while (true)
        {

            int flag = false;

            for (int i{}; i < playersNumber; i++)
            {
                move(i);

                if (players[i].getPosition() >= map.getSize())
                {
                    flag = true;
                    std::cout << players[i].getName() << " wins\n";
                    break;
                }
            }

            if (flag)
                break;
        }
    }

private:
    int snakesNumber;
    int playersNumber = 2;
    std::vector<Player> players;
    std::vector<Snake> snakes;
    Map map;
};