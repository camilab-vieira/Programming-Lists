#include "queue.h"
#include <iostream>
#include <cstddef>

using namespace std;

template<class E>Link* Queue<E>::createNullLink(){
    Link *link;
    link = new Link;
    link->element = NULL;
    link->next = NULL;
    return link;
}

template<class E>Link* Queue<E>::createLink(int item, Link* nextval){
    Link *link;
    link = new Link;
    link->element = item;
    link->next = nextval;
    return link;
}

template <class E>Queue<E>::Queue(){
    Link *link;
    link = createNullLink();
    this->front = link;
    this->rear = link;
    this->size = 0;
}

template<class E>void Queue<E>::enqueue(E item){
    Link* link;
    link = createLink(item, NULL);
    this->rear->next = link;
    this->rear = link;
    this->size++;
}

template <class E> int Queue<E>::length(){
    return this->size;
}

template<class E> void Queue<E>::printQueue(){
    Link* temp = this->front->next;
    cout<<"<";
    if(this->front == this->curr) cout<<"|";
    for(int i = 0; i < this->size; i++){
        cout<<temp->element;
        if(temp == this->curr) cout<<"|";
        if(i < this->size - 1) cout<<" ";
        temp = temp->next;
    }
    cout<<">";
}

template <class E> E Queue<E>::frontValue(){
    return this->front->element;
}

template <class E> E Queue<E>::dequeue(){
    if(this->size == 0) return NULL;
    Link* temp = this->front->next;
    E item = this->front->next->element;
    this->front->next = this->front->next->next;
    if(this->front->next == NULL) this->rear = this->front;
    this->size--;
    delete temp;
    return item;
}

template <class E> void Queue<E>::clear(){
    Link* temp = this->front;
    Link* aux;
    for(int i = 0; i <= this->size; i++){
        aux = temp;
        temp = temp->next;
        delete aux;
    }
    this->front->next = NULL;
    this->rear = this->front;
    this->size = 0;
}