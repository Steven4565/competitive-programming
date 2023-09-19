#include <iostream>
#include <string>
#include <vector>

using namespace std;

void permute(vector<int> &arr, int idx, vector<int> &permutArr) {
  if (idx == arr.size() - 1) {
    // print()
  }
  //
}

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  vector<int> permutArr(n);
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }
  permute(arr, 0, permutArr);

  return 0;
}