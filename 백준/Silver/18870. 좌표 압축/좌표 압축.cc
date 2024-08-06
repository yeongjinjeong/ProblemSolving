#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    set<int> s;
    
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    vector<int>sorted2;
    for (auto it = s.begin(); it != s.end(); it++) {
        sorted2.push_back(*it);
        
    }
    
    //set의 시작과 끝 이터레이터로 vector를 만든다.
    //방법1
    vector<int> sortedArr(s.begin(), s.end());
    //방법2
    /*vector<int>sorted2;
    for (auto it = s.begin(); it != s.end(); it++) {
        sorted2.push_back(*it);

    }*/

    for (int i = 0; i < N; i++) {
        int ind = lower_bound(sortedArr.begin(), sortedArr.end(), arr[i]) - sortedArr.begin();
        cout << ind << ' ';
    }

    return 0;
}
