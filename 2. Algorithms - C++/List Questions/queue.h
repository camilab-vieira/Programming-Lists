#ifndef QUEUE_H
#define QUEUE_H


typedef struct Link{
    int element;
    Link* next;
};

template <class E>
class Queue{
    private:
        Link* front;
        Link* rear;
        int cnt;
    public:
        Link* createNullLink();
        Link* createLink(int item, Link* nextval);
        Queue();
        void enqueue(E item);
        int length();
        void printQueue();
        E frontValue();
        E dequeue();
        void clear();
};


#endif