#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int compare(string a, string b) { return a.compare(b) < 0; }

int find(vector<string> &arr, int len, string x) {
  int l = 0;
  int r = len;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] == x) {
      return m;
    } else if (arr[m].compare(x) < 0) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<string> arr(n);
  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    arr[i] = input;
    sort(arr.begin(), arr.begin() + i + 1, compare);
    int idx = find(arr, i, input) + 1;
    cout << idx << endl;
  }

  return 0;
}