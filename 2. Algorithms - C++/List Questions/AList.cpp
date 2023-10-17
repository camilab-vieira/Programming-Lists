#include <iostream>
#include <cstddef>
#include "AList.h"

using namespace std;

template <class E>List<E>::List(){
    this->maxSize = 50;
    this->listSize = 0;
    this->curr = 0;
    this->listArray = new E[this->maxSize];
}

template<class E>List<E>::List(int size){
    this->maxSize = size;
    this->listSize = 0;
    this->curr = 0;
    this->listArray = new E[this->maxSize];
}

template<class E>List<E>::~List(){
    delete[] listArray;
}

template<class E>void List<E>::insert(E item){
    int i;
    if(this->listSize >= this->maxSize){} 
    else{
    i = this->listSize;
    while(i > this->curr){

        this->listArray[i] = this->listArray[i - 1];
        i--;
    }
    this->listArray[this->curr] = item;
    this->listSize++;
    }
}

template <class E> void List<E>::append(E item){
    if(this->listSize >= this->maxSize){} 
    else{
    this->listArray[this->listSize] = item;
    this->listSize++;
    }
}

template <class E> void List<E>::prev(){
    if(this->curr != 0) this->curr--;
}

template <class E> void List<E>::next(){
    if(this->curr < this->listSize) this->curr++;
}

template <class E> void List<E>::moveToStart(){
    this->curr = 0;
}

template <class E> void List<E>::moveToEnd(){
    this->curr = this->listSize;
}

template <class E> int List<E>::length(){
    return this->listSize;
}

template <class E> int List<E>::currPos(){
    return this->curr;
}

template <class E> void List<E>::moveToPos(int pos){
    this->curr = pos;
}

template <class E> void List<E>::printList(){
    for(int i = 0; i < this->listSize; i++)
        cout<<this->listArray[i]<<" ";
    cout<<"\n";
}

template <class E> E List<E>::getValue(){
    return this->listArray[this->curr];
}

template <class E> int List<E>::count(E item){
    int i = 0, count = 0;
    while(i < this->listSize){
        if(this->listArray[i] == item) count++;
        i++;
    }
    return count;
}

template <class E> E List<E>::remove(){
    E item; int i;
    if(this->curr < 0 || this->curr >= this->listSize) return NULL;
    item = this->listArray[this->curr]; 
    i = this->curr;
    while(i < this->listSize - 1){
        this->listArray[i] = this->listArray[i + 1];
        i++;
    }
    this->listSize--;
    return item;
}

template <class E> void List<E>::clear(){
    this->listSize = 0;
    this->curr = 0;
}