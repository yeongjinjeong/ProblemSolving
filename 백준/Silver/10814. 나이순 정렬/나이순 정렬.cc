#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Person {
    int age;
    int order;
    string name;
 
};
bool cmp(Person left, Person right) {
    if (left.age < right.age) return true;
    if (left.age > right.age) return false;

    if (left.order < right.order) return true;
    if (left.order < right.order) return false;

    return false;
}
int main() {
    int N;
    cin >> N;
    vector<Person>members(N);
    for (int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;
        members[i] = { age,i,name };
    }
    sort(members.begin(), members.end(),cmp);

    for (int i = 0; i < members.size(); i++) {
        cout << members[i].age << ' '<< members[i].name << "\n";
    }
    return 0;
    
}
