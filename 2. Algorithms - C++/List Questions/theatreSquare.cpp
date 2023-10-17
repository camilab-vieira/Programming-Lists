#include <iostream>

int main(){
    int m, n, a;
    long long int side1, side2, answer;

    std::cin>>m; 
    std::cin>>n;
    std::cin>>a;

    side1 = m/a;
    if(m%a != 0)
        side1++;
    side2 = n/a;
    if(n%a != 0)
        side2++;
    answer = side1 * side2;

    std::cout<<answer<<"\n"; 
    
    return 0;
}