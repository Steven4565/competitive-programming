#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

ll n, d;
pair<ll, ll> entries[100001];

ll comp(pair<ll, ll> a, pair<ll, ll> b) { return a.first < a.second; }

signed main() {
  cin >> n >> d;
  for (ll i = 0; i < n; i++) {
    // price, ducks
    cin >> entries[i].first >> entries[i].second;
  }

  sort(entries, entries + n);

  ll ducksHappy = 0;
  for (ll i = 0; i < n; i++) {
    if (d <= 0)
      break;
    while (d - entries[i].first >= 0 && entries[i].second > 0) {
      ducksHappy++;
      d -= entries[i].first;
      entries[i].second--;
    }
  }

  cout << ducksHappy << endl;

  return 0;
}