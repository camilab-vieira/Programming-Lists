#include <iostream>
#include <string>
#include "stack.cpp"

using namespace std;

int main(){
    int i, j, k = 0, casos, item, sum = 0, stop = 0;
    string comando[2];

    cin>>casos;
    Stack<int> stack[casos];
    for(i = 0; i < casos; i++){
        while(cin>>comando[0]){
        //while(!stop){
            //cin>>comando[0];
            if(comando[0] == "end") {stop = 1; return 0;}
            cin>>comando[1];
            item = stoi(comando[1]);
            if(comando[0] == "push"){
                stack[i].push(item);
                stack[i].printStack();
            }
            if(comando[0] == "pop"){
                for(j = 0; j < item; j++){
                    sum += stack[i].pop();
                }
                cout<<sum<<"\n";
                sum = 0;
                stack[i].printStack();
            }
            k++;
        }
    }

    return 0;
}
