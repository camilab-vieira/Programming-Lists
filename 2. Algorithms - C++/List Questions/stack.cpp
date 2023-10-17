#include "stack.h"
#include <iostream>
#include <cstddef>

using namespace std;

template<class E>Stack<E>::Stack(){
    this->top = NULL;
    this->size = 0;
};

template<class E>Link* Stack<E>::createLink(int item, Link* nextval){
    Link *link;
    link = new Link;
    link->element = item;
    link->next = nextval;
    return link;
}

template<class E>void Stack<E>::push(E item){
    Link* link;
    link = createLink(item, this->top);
    this->top = link;
    this->size++;
}
template<class E>E Stack<E>::pop(){
    if(this->top == NULL){}
    else{
        E item = this->top->element;
        this->top = this->top->next;
        this->size--;
        return item;
    }
}
template<class E>E Stack<E>::topValue(){
    return top->element;
}
template<class E>void Stack<E>::printStack(){
    Link* temp = this->top;
    for(int i = 0; i < this->size; i++){
        cout<<temp->element<<" ";
        temp = temp->next;
    }
}
template<class E>int Stack<E>::lenght(){
    return this->size;
}
template<class E>void Stack<E>::clear(){
    Link* temp = this->top;
    Link* aux;
    for(int i = 0; i <= this->size; i++){
        aux = temp;
        temp = temp->next;
        delete aux;
    }
    this->top = NULL;
    this->size = 0;
}