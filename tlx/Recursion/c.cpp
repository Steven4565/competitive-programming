#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(vector<int> &arr) {
  if (arr.size() <= 2)
    return true;
  bool prevBigger = arr[0] > arr[1];

  for (int i = 2; i < arr.size(); i++) {
    if (arr[i - 1] > arr[i] == prevBigger) {
      return false;
    }
    prevBigger = !prevBigger;
  }
  return true;
}

void permute(vector<int> &arr, int idx) {
  if (idx == arr.size() - 1) {
    if (!check(arr))
      return;
    for (int i = 0; i < arr.size(); i++) {
      cout << arr[i];
    }
    cout << endl;
    return;
  }
  for (int i = idx; i < arr.size(); i++) {
    swap(arr[i], arr[idx]);
    permute(arr, idx + 1);
    swap(arr[i], arr[idx]);
  }
}

void permute2(vector<int> &buffer, int idx, int n, int used) {
  if (idx > n - 1) {
    if (!check(buffer))
      return;
    for (int i = 0; i < n; i++) {
      cout << buffer[i];
    }
    cout << endl;
  }

  for (int i = 0; i < n; i++) {
    if (0 == (used & (1 << i))) {
      buffer[idx] = i + 1;
      permute2(buffer, idx + 1, n, (1 << i) | used);
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }
  // permute(arr, 0);

  vector<int> buffer(n);
  permute2(buffer, 0, n, 0);

  return 0;
}