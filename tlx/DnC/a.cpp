#include <iostream>
#include <limits.h>
#include <stdint.h>
using namespace std;

typedef long long ll;

ll n, m;
ll arr[300000];

ll count(ll x) {
  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    if (sum > m)
      return m + 1;
    sum += x / arr[i];
  }
  return sum;
}

ll binSearchLower(ll m) {
  ll l = 0;
  ll r = LONG_LONG_MAX;
  ll ans;
  while (l <= r) {
    ll mid = l + (r - l) / 2;
    ll res = count(mid);

    if (res < m) {
      l = mid + 1;
    } else {
      ans = mid;
      r = mid - 1;
    }
  }
  return ans;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << binSearchLower(m + 1) - binSearchLower(m) << endl;
  return 0;
}