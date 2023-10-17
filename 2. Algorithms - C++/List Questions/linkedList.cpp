#include "linkedList.h"
#include <iostream>
#include <cstddef>

using namespace std;

template<class E>Link* List<E>::createNullLink(){
    Link *link;
    link = new Link;
    link->element = NULL;
    link->next = NULL;
    return link;
}

template<class E>Link* List<E>::createLink(int item, Link* nextval){
    Link *link;
    link = new Link;
    link->element = item;
    link->next = nextval;
    return link;
}

template <class E>List<E>::List(){
    Link *link;
    link = createNullLink();
    this->head = link;
    this->curr = link; 
    this->tail = link;
    this->cnt = 0;
}

template<class E>void List<E>::insert(E item){
    Link* link;
    link = createLink(item, this->curr->next);
    this->curr->next = link;
    if(this->tail == this->curr){
        this->tail = this->curr->next;
    }
    this->cnt++;
}

template<class E>void List<E>::insertAndMoveCurr(E item){
    Link* link;
    link = createLink(item, this->curr->next);
    this->curr->next = link;
    if(this->tail == this->curr){
        this->tail = this->curr->next;
    }
    this->curr = link;
    this->cnt++;
}

template <class E> void List<E>::append(E item){
    Link* link;
    link = createLink(item, NULL);
    this->tail->next = link;
    this->tail = link;
    this->cnt++;
}

template <class E> void List<E>::prev(){
    if(this->curr != this->head){
        Link* temp = this->head;
        while(temp->next != this->curr){
            temp = temp->next;
        }
        this->curr = temp;
    }
}

template <class E> void List<E>::next(){
    if(this->curr != this->tail) this->curr = this->curr->next;
}

template <class E> void List<E>::moveToStart(){
    this->curr = this->head;
}

template <class E> void List<E>::moveToEnd(){
    this->curr = this->tail;
}

template <class E> int List<E>::length(){
    return this->cnt;
}

template <class E> int List<E>::currPos(){
    return this->curr;
}

template <class E> void List<E>::moveToPos(int pos){
    Link* temp = this->head;
    for(int i = 0; i < pos; i++){
        temp = temp->next;
    }
    this->curr = temp;
}

template<class E> void List<E>::printList(){
    Link* temp = this->head->next;
    for(int i = 0; i < this->cnt; i++){
        cout<<temp->element;
        temp = temp->next;
    }
}

template <class E> E List<E>::getValue(){
    return this->curr->element;
}

template <class E> int List<E>::count(E item){
    int count = 0;
    Link* temp = this->head;
    for(int i = 0; i <= this->cnt; i++){
        if(temp->element == item) count++;
        temp = temp->next;
    }
    return count;
}

template <class E> E List<E>::remove(){
    if(this->curr->next == NULL) return NULL;
    Link* temp = this->curr;
    E item = this->curr->next->element;
    if(this->tail == this->curr->next) this->tail = this->curr;
    this->curr->next = this->curr->next->next;
    this->cnt--;
    delete temp;
    return item;
}

template <class E> void List<E>::clear(){
    Link* temp = this->head;
    Link* aux;
    for(int i = 0; i <= this->cnt; i++){
        aux = temp;
        temp = temp->next;
        delete aux;
    }
    this->head->next = NULL;
    this->curr = this->head; 
    this->tail = this->head;
    this->cnt = 0;
}