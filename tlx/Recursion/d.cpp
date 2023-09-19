#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printArr(vector<int> &arr) {
  for (auto x : arr) {
    cout << x << " ";
  }
  cout << endl;
}

void combination(vector<int> &buffer, int idx, int start, int n, int k) {
  if (idx == k) {
    printArr(buffer);
    return;
  }

  for (int i = start; i < n; i++) {
    buffer[idx] = i + 1;
    if (idx != 0 && buffer[idx - 1] >= buffer[idx]) {
      break;
    }
    combination(buffer, idx + 1, i + 1, n, k);
  }
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> buffer(k);
  combination(buffer, 0, 0, n, k);

  return 0;
}