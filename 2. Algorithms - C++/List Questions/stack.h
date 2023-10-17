#ifndef STACK_H
#define STACK_H

typedef struct Link{
    int element;
    Link* next;
};

template <class E>
class Stack{
    private:
        Link* top;
        int size;
    public:
        Stack();
        Link* createLink(int item, Link* nextval);
        void push(E item);
        E pop();
        E topValue();
        void printStack();
        int lenght();
        void clear();
};

#endif