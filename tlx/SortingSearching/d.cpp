#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long searchBiggerThan(vector<long long> &arr, long long x, int len) {
  long long l = 0;
  long long r = len;
  long long ans = -1;

  while (l <= r) {
    long long m = l + (r - l) / 2;
    if (arr[m] <= x) {
      // go right
      l = m + 1;
    } else {
      ans = m;
      r = m - 1;
    }
  }

  return ans;
}

long long searchLessEqualsThan(vector<long long> &arr, long long x, int len) {
  long long l = 0;
  long long r = len;
  long long ans = -1;

  while (l <= r) {
    long long m = l + (r - l) / 2;
    if (arr[m] > x) {
      // go left
      r = m - 1;
    } else {
      // go right
      l = m + 1;
      ans = m;
    }
  }
  return ans;
}

signed main() {
  long long n;
  cin >> n;
  vector<long long> ducks(n);
  for (long long i = 0; i < n; i++) {
    cin >> ducks[i];
  }

  long long q;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    long long min, max;
    cin >> min >> max;

    long long bg = searchBiggerThan(ducks, min, n - 1);
    // bg = bg == -1 ? 0 : bg;
    // cout << bg << endl;

    long long ls = searchLessEqualsThan(ducks, max, n - 1);
    // ls = ls == -1 ? ducks.size() : ls;
    // cout << ls << endl;

    if (bg == -1 || ls == -1) {
      cout << 0 << endl;
    } else {
      cout << ls - bg + 1 << endl;
    }
  }

  return 0;
}