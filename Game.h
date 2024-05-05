#include<iostream>
#include<vector>

class Snake{

public:

    int getHead(){ return head ; }
    int getTail(){ return tail ; }

    void setTail( int tail ){ this->tail = tail ; }
    void setHead( int head ){ this->head = head ; }

private:

    int head ;
    int tail ;

};