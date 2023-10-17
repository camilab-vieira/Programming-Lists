#include <iostream>
#include <string>
#include "AList.cpp"

using namespace std;

int main(){
    int i, j, casos, numOp, item, count = 0;
    string comando[2];

    cin>>casos;
    List<int> list[casos];
    for(i = 0; i < casos; i++){
        cout<<"Caso "<<i+1<<": \n";
        cin>>numOp;
        for(j = 0; j < numOp; j++){
            cin>>comando[0];
            if(comando[0] == "insert"){
                cin>>comando[1];
                item = stoi(comando[1]);
                list[i].insert(item);
                list[i].printList();
            }if(comando[0] == "remove"){
                list[i].remove();
                list[i].printList();
            }if(comando[0] == "count"){
                cin>>comando[1];
                item = stoi(comando[1]);
                count = list[i].count(item); 
                cout<<count<<"\n";
                list[i].printList();
            }if(comando[0] == "prev"){
                list[i].prev();
                list[i].printList();
            }if(comando[0] == "next"){
                list[i].next();
                list[i].printList();
            }
        }
    }

    return 0;
}