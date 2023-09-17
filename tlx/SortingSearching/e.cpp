#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int compare(string a, string b) {
  int aSize = a.size();
  int bSize = b.size();

  if (aSize != bSize) {
    return aSize < bSize;
  }

  return a.compare(b) < 0;
}

int main() {
  int n;
  cin >> n;
  string arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n, compare);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
  return 0;
}