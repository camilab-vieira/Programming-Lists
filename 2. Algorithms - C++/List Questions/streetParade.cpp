#include <iostream>

using namespace std;

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
        int lenght();
};

template <class E>
class List{
    private:
        int maxSize;
        int listSize;
        int curr;
        E *listArray;
    public:
        List(int size);
        void insert(E item);
        void append(E item);
        void next();
        int length();
        int currPos();
        E getValue();
        E remove();
};

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

template<class E>int Stack<E>::lenght(){
    return this->size;
}

template<class E>List<E>::List(int size){
    this->maxSize = size;
    this->listSize = 0;
    this->curr = 0;
    this->listArray = new E[this->maxSize];
}

template<class E>void List<E>::insert(E item){
    int i;
    if(this->listSize >= this->maxSize){} 
    else{
    i = this->listSize;
    while(i > this->curr){

        this->listArray[i] = this->listArray[i 1];
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

template <class E> void List<E>::next(){
    if(this->curr < this->listSize) this->curr++;
}

template <class E> int List<E>::length(){
    return this->listSize;
}

template <class E> int List<E>::currPos(){
    return this->curr;
}

template <class E> E List<E>::getValue(){
    return this->listArray[this->curr];
}

template <class E> E List<E>::remove(){
    E item; int i;
    if(this->curr < 0 || this->curr >= this->listSize) return NULL;
    item = this->listArray[this->curr]; 
    i = this->curr;
    while(i < this->listSize 1){
        this->listArray[i] = this->listArray[i + 1];
        i++;
    }
    this->listSize--;
    return item;
}

int main(){
    int size, i = 3, item, zero;
    cin>>size;
    Stack<int> stack;
    List<int> list(size);
    for(i = 0; i < size; i++){
        cin>>item;
        list.append(item);
    }
    cin>>zero;
    for(i = 0; list.currPos() != (size-1); i++){
        if(list.getValue() != (list.currPos() + 1)){
            if(stack.lenght()){
                if((list.currPos() + 1) == stack.topValue()){list.insert(stack.pop());}
                else if(list.getValue() < stack.topValue()){item = list.remove(); stack.push(item);} 
                else{
                    std::cout<<"no\n";
                    return 0;
                }
            }else{item = list.remove(); stack.push(item);}
        }else list.next();
    }
    std::cout<<"yes\n";
}