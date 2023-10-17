#include <iostream>
#include <cstddef>
#include "AList.h"
#include "dictionary.h"

using namespace std;

template<class E>Key* Dictionary<E>::createEntry(char* element, int indice){
    Key *key;
    key = new Key;
    key->element = element;
    key->indice = indice;
    return key;
}

/*template<class E>Dictionary<E>::Dictionary(int size, int h(char* K), ){
    this->hashSize = size; 
    this->cnt = 0;
    this->H = new List(size);
    this->Perm = createPerm(p)
    this->hashing = h;
}*/

template<class E>Dictionary<E>::~Dictionary(){
    delete[] listArray;
}

template<class E>void Dictionary<E>::insert(Dictionary d, Key k, E e){
    int pos, l, entry;
    if(find(d, k) == NULL){
        pos = this->hashing(k);
        l = this->hash[pos];
        entry = createEntry(k, e);
        list[pos].append(l, entry);
    }
}

template <class E> E Dictionary<E>::find(Dictionary d, Key k){}; 
template <class E> int Dictionary<E>::size(Dictionary d){};
template <class E> E Dictionary<E>::remove(Dictionary d, Key k){};
template <class E> E Dictionary<E>::removeAny(Dictionary d){};
