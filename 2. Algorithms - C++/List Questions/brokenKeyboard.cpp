#include <iostream>
#include <string>

using namespace std;

typedef struct Link{
    char element;
    Link* next;
};

template <class E>
class List{
    private:
        Link* head;
        Link* tail;
        Link* curr;
        Link* start;
        int cnt;
    public:
        Link* createLink(int item, Link* nextval);
        List();
        void insertAndMoveCurr(E item);
        void moveToStartLine();
        void moveToEnd();
        void printList();
};

template<class E>Link* List<E>::createLink(int item, Link* nextval){
    Link *link;
    link = new Link;
    link->element = item;
    link->next = nextval;
    return link;
}

template <class E>List<E>::List(){
    Link *link;
    link = createLink(NULL,NULL);
    this->head = link;
    this->curr = link; 
    this->tail = link;
    this->start = link;
    this->cnt = 0;
}

template<class E> void List<E>::insertAndMoveCurr(E item){
    Link* link;
    link = createLink(item, this->curr->next);
    if(item == '\n'){
    this->curr = this->tail;
    this->start = link;
    }
    this->curr->next = link;
    if(this->tail == this->curr){
        this->tail = this->curr->next;
    }
    this->curr = link;
    this->cnt++;
}

template <class E> void List<E>::moveToStartLine(){
    this->curr = this->start;
}

template <class E> void List<E>::moveToEnd(){
    this->curr = this->tail;
}

template<class E> void List<E>::printList(){
    Link* temp = this->head->next;
    for(int i = 0; i < this->cnt; i++){
        cout<<temp->element;
        temp = temp->next;
    }
}

int main(){
    char letter;
    List<char> list;
    while(cin.get(letter)){
        if(letter == '[') list.moveToStartLine();
        else if(letter == ']') list.moveToEnd(); 
        else list.insertAndMoveCurr(letter);
    }
    list.printList();
    return 0;
}