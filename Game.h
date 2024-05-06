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

private:

    int size ;

};


class Player{

public:


    std::string getName(){ return name ; }
    int getBite(){ return bite ; }
    int getposition (){ return position ;}


    void setName( std::string name ){ this->name = name ; }
    void setBite( int bite ){ this->bite = bite ; }
    void addBite(){ bite++ ; } // to add one to the number of bites
    void setPosition( int position ){ this-> position = position ; }
    void addToPosition( int roll ){ position += roll ; }

    //to roll dice
    int roll(){

        
        int roll1 = rand()%6 +1 ;
        int roll2  = 0 ;
        
        if(roll1 == 6)
            roll2 += rand()%6 + 1 ;

        return roll1 + roll2 ;

    }

private:

    int position = 1 ;
    std::string name ;
    int bite = 0 ; //to hold the number of snake's bites

};


class Game{

public:

        //to insert a random snake
    void randomSnake(){

        Snake snake ;
        int randomHead = rand()%map.getSize() + 1 ;
        int randomTail = rand()%map.getSize() + 1 ;
        snake.setHead(randomHead) ;
        snake.setTail(randomTail) ;
        snakes.push_back(snake) ;

    }


    //to get inputs from user
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

            snakes.push_back(snake) ;

        }
    }

    //to run game
    void run(){

        InputData() ;

        while (true){
            bool flag = false ;
            //first player rolling
            int roll1 = players[0].roll() ;
            players[0].addToPosition(roll1) ;
            std::cout<<players[0].getName()<<" rolled "<<roll1<<" and is on "<<players[0].getposition()<<std::endl ;

            for(int i =0 ; i<snakesNumber ; i++){

                if(snakes[i].getHead() == players[0].getposition()){

                    flag = true ;
                    players[0].setPosition(snakes[i].getTail()) ;
                    players[0].addBite() ;
                    break;

                }

            }
            if(flag){
                std::cout<<players[0].getName()<<" bited and now is on: "<<players[0].getposition()<<std::endl ;
                flag = false ;
            }

            
            //second player rolling
            int roll2 = players[1].roll() ;
            players[1].addToPosition(roll2) ;
            std::cout<<players[1].getName()<<" rolled "<<roll2<<" and is on "<<players[1].getposition()<<std::endl ;
            
            for(int i = 0 ; i<snakesNumber ; i++){

                if(snakes[i].getHead() == players[1].getposition()){
                    flag = true ;
                    players[1].setPosition(snakes[i].getTail()) ;
                    break;

                }
                
            }
            if(flag){
                std::cout<<players[1].getName()<<" bited and now is on: "<<players[1].getposition()<<std::endl ;
                flag = false ;
            }


            for(int i{} ; i<playersNumber ; i++){
                if(players[i].getBite() ==2){
                    players[i].setBite(0) ;
                    randomSnake() ;
                }

            }

            if(players[0].getposition() >= map.getSize() ||players[1].getposition() >= map.getSize())
                break;

            

            
        }
        


    }



private:

    int snakesNumber ;
    int playersNumber = 2 ;
    std::vector<Player> players ;
    std::vector<Snake> snakes ;
    Map map ;

};