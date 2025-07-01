#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int num;
    int freq;
    int when;
};

bool cmp(Node left, Node right) {
    return left.num < right.num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int cnt;
    cin >> cnt;
    vector<Node> arr(N, {0, 0, -1});

    for (int t = 0; t < cnt; t++) {
        int n;
        cin >> n;

        bool found = false;
        int found_idx = 0;
        for (int j = 0; j < N; j++) {
            if (arr[j].num == n) {
                arr[j].freq++;
                found = true;
                break;
            }
        }

        if (!found) {
            int min_idx = 0;
            for (int j = 1; j < N; j++) {
                if (arr[j].freq < arr[min_idx].freq)
                    min_idx = j;
                else if (arr[j].freq == arr[min_idx].freq && arr[j].when < arr[min_idx].when)
                    min_idx = j;
            }
            arr[min_idx] = {n, 1, t};
        }
    }

    sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < N; i++) {
        if (arr[i].num != 0)
            cout << arr[i].num << " ";
    }

    return 0;
}

