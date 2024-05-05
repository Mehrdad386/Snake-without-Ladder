#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>


class Snake{

public:

    Snake(int head , int tail){

        setHead(head) ;
        setTail(tail) ;

    }

    Snake(){

        head = 0 ;
        tail = 0 ;

    }

    int getHead(){ return head ; }

    int getTail(){ return tail ; }
    
    void setTail( int tail ){ this->tail = tail ; }

    void setHead( int head ){ this->head = head ; }

private:

    int head ; //to hold head of the snake position
    int tail ; //to hold tail of the snake position

};



class Map{

public:

    int getSize(){ return size ; }

    void setSize( int size ){ this->size = size ; }

    //to insert a random snake
    void randomSnake(){

        std::srand(time(0)) ;
        int randomHead = rand()%size + 1 ;
        int randomTail = rand()%size + 1 ;
        pushSnake(randomHead , randomTail) ;

    }

    //to push a new snake to snakes list
    void pushSnake(int head , int tail){
        
        Snake snake(head , tail) ;
        snakes.push_back(snake) ;

    }
    

private:

    int size ;
    std::vector<Snake> snakes ;

};


class Player{

public:

    std::string getName(){ return name ; }
    int getBite(){ return bite ; }

    void setName( std::string name ){ this->name = name ; }
    void setBite( int bite ){ this->bite = bite ; }
    void addBite(){ bite++ ; } // to add one to the number of bites

    //to roll dice
    int roll(){

        std::srand(time(0)) ;
        int roll = rand()%6 +1 ;
        
        if(roll == 6)
            roll += rand()%6 + 1 ;

        return roll ;

    }

private:

    std::string name ;
    int bite ; //to hold the number of snake's bites to the player

};


class Game{

public:

    void InputData(){

        
        int size ;
        std::cin>>size ;
        map.setSize(size) ;
        
        Player player ;
        std::string name ;

        for(int i{} ; i<playersNumber ; i++){
            
            std::cin>>name ;
            player.setName(name) ;
            players.push_back(player) ;
        
        }

        std::cin>>snakesNumber ;

        Snake snake ;
        int position ;

        for(int i{} ; i<snakesNumber ; i++){
            
            std::cin>>position ;
            snake.setHead(position) ;

            std::cin>>position ;
            snake.setTail(position) ;

        }
    }

private:

    int snakesNumber ;
    int playersNumber = 2 ;
    std::vector<Player> players ;
    Map map ;

};