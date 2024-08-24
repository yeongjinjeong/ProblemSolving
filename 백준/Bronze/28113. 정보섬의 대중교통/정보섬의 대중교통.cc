#include <iostream>
using namespace std;
 
int main(){
    int N,A,B;
    cin >> N >> A >> B;
    if(A<B && N+A > A){
        cout <<"Bus";
    }
    else if ( A>B && B < N+A){
        cout << "Subway";
    
    }
    else{
        cout << "Anything";
    }
}