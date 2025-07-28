#include <iostream>

using namespace std;

int n, m;
int arr[101] = { 0, };
int a, b;

void swap(int a, int b) {
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

int main() {
  cin >> n >> m;

  for(int i = 1; i <= n; i++) {
    arr[i] = i;
  }

  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    swap(a, b); 
  }

  for(int i = 1; i <= n; i++) {
    cout << arr[i] << ' ';
  }

  return 0;
}