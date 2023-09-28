#include <iostream>
using namespace std;
typedef long long ll;

int n, q, input;
int arr[100001];

int binser(int x) {
  int l = 0;
  int r = n - 1;
  int ans = -1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] == x) {
      ans = m;
      break;
    } else if (arr[m] < x) {
      l = m + 1;
    } else if (arr[m] > x) {
      ans = m;
      r = m - 1;
    }
  }
  return ans;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> input;
    if (i != 0) {
      arr[i] = arr[i - 1] + input;
    } else {
      arr[0] = input;
    }
  }

  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> input;
    cout << binser(input) + 1 << endl;
  }

  return 0;
}