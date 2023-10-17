#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Link{
    int element;
    Link* next;
};

template <class E>
class List{
    private:
        Link* head;
        Link* tail;
        Link* curr;
        int cnt;
    public:
        Link* createNullLink();
        Link* createLink(int item, Link* nextval);
        List();
        void insert(E item);
        void insertAndMoveCurr(E item);
        void append(E item);
        void prev();
        void next();
        void moveToStart();
        void moveToEnd();
        int length();
        int currPos();
        void moveToPos(int pos);
        void printList();
        E getValue();
        int count(E item);
        E remove();
        void clear();
};


#endif