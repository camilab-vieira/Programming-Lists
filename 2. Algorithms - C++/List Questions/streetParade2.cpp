#include <iostream>

using namespace std;

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
        void printList();
        E getValue();
        E remove();
        void clear();
};

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

template <class E> void List<E>::next(){
    if(this->curr < this->listSize) this->curr++;
}

template <class E> int List<E>::length(){
    return this->listSize;
}

template <class E> int List<E>::currPos(){
    return this->curr;
}

template <class E> void List<E>::printList(){
    for(int i = 0; i < this->listSize; i++)
        cout<<this->listArray[i]<<" ";
    cout<<"\n";
}

template <class E> E List<E>::getValue(){
    return this->listArray[this->curr];
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

int main(){
    int i, size, item;
    std::cin>>size;
    while(size != 0){
        List<int> list1(size);
        List<int> list2(size);
        for(i = 0; i < size; i++){
            std::cin>>item;
            list1.append(item);
        }
        i = 1;
        item = 1;
        while(i <= size){
            /*cout<<"list 1: ";
            list1.printList();
            cout<<"list 2: ";
            list2.printList();
            cout<<"i: "<< i<<"\n";
            cout<<"valor 1: "<< list1.getValue()<<"\n";
            cout<<"valor 2: "<< list2.getValue()<<"\n";
            list2.printList();*/
            if(list2.length() > 0){
                if(list2.getValue() == i){
                    list1.insert(list2.remove());
                }
            }
            if(list1.getValue() != i){
                if(list2.length() > 0){
                    if(list2.getValue() > list1.getValue()){
                        list2.insert(list1.remove());
                    }else{
                        cout<<"no\n";
                        list1.clear();
                        list2.clear();
                        i = size + 1;
                        item = 0;
                    }
                }
                if(list2.length() == 0){
                    list2.insert(list1.remove());
                }
            }else{list1.next(); i++;}
        }
        if(item) cout<<"yes\n";
        list1.clear();
        list2.clear();
        std::cin>>size;
    }
    return 0;
}


/*#include <iostream>

using namespace std;

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
        void printList();
        E getValue();
        E remove();
        void clear();
};

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

template <class E> void List<E>::next(){
    if(this->curr < this->listSize) this->curr++;
}

template <class E> int List<E>::length(){
    return this->listSize;
}

template <class E> int List<E>::currPos(){
    return this->curr;
}

template <class E> void List<E>::printList(){
    for(int i = 0; i < this->listSize; i++)
        cout<<this->listArray[i]<<" ";
    cout<<"\n";
}

template <class E> E List<E>::getValue(){
    return this->listArray[this->curr];
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

int main(){
    int i, size, item, no = 0;
    cin>>size;
    while(size != 0){
	    List<int> list1(size);
	    List<int> list2(size);
	    for(i = 0; i < size; i++){
	        cin>>item;
	        list1.append(item);
	    }
	    no = 0;
	    for(i = 0; list1.currPos() != size; i++){
	        if(list2.length()){
	            if(list2.getValue() == list1.currPos() + 1){
	                list1.insert(list2.remove());
	
	            }
	            if(list1.length() == list1.currPos() + 1){
	                list1.append(list2.remove());
	
	            }
	        }
	        if(list1.getValue() != list1.currPos() + 1){
	            item = list1.remove();
	            if(list2.length()){
	                if(item < list2.getValue())
	                    list2.insert(item);
	                else{
	                    cout<<"no\n";
	                    list2.clear();
	                    no = 1;
	                }
	            } 
	            else list2.append(item);
	        }else list1.next();
	    }
	    if(!no) cout<<"yes\n";
	    cin>>size;
    }
    return 0;
}*/