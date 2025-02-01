#include <iostream>
#include <string>

using namespace std;

int main(){
    int a, b,c;
    cin >>a;
    cin >>b;
    cin >>c;
    string A,B,C;
    A = to_string(a);
    B = to_string(b);
    C = to_string(c);
    
    cout << a+b-c <<"\n";
    cout << stoi(A+B)-stoi(C);
    
}
