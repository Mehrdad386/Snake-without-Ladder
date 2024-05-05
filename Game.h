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

    int head ;
    int tail ;

};



class Map{

public:

    int getSize(){ return size ; }

    void randomSnake(){

        std::srand(time(0)) ;
        int randomHead = rand()%size + 1 ;
        int randomTail = rand()%size + 1 ;
        pushSnake(randomHead , randomTail) ;

    }

    void pushSnake(int head , int tail){
        
        Snake snake(head , tail) ;
        snakes.push_back(snake) ;

    }
    

private:

    int size ;
    std::vector<Snake> snakes ;

};