#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ll;

ll n, m;
pair<int, ll> prices[11];
vector<ll> counts(11, 0);

int comp(pair<int, ll> a, pair<int, ll> b) {
  return a.second < b.second || (a.second == b.second && a.first > b.first);
}

int main() {
  cin >> n;
  n++;
  for (int i = 0; i < n; i++) {
    prices[i].first = i;
    cin >> prices[i].second;
  }
  cin >> m;

  sort(prices, prices + n, comp);

  // for (int i = 0; i < n; i++) {
  //   cout << prices[i].first << " " << prices[i].second << endl;
  // }

  // get max number of plates you can buy
  ll leastPrice = prices[0].second;
  counts[prices[0].first] = m / leastPrice;
  int maxPlates = m / leastPrice;
  // cout << "max " << maxPlates << endl;

  ll count = m / leastPrice;
  ll remainder = m % leastPrice;
  // cout << "rem " << remainder << endl;
  for (int i = n - 1; i >= 0 && remainder > 0 && maxPlates > 0; i--) {
    if (i - 1 >= 0 && prices[i - 1].second == prices[i].second)
      continue;

    ll diff = prices[i].second - leastPrice;
    // cout << "diff " << diff << endl;
    if (diff != 0 && diff <= remainder && remainder != 0) {
      ll bought = remainder / diff;
      remainder %= diff;
      // cout << "bought " << bought << " " << prices[i].first << endl;
      counts[prices[i].first] += bought;
      counts[prices[0].first] -= bought;
    }
  }

  // total bought
  if (count == 0) {
    cout << count << endl;
    return 0;
  } else if (count == counts[0])
    cout << 1 << endl;
  else
    cout << count << endl;

  // first 50 digits of max comb
  vector<ll> countsCopy = counts;
  if (countsCopy[0] == count) {
    cout << 0;
  } else {
    int j = n - 1;
    for (int i = maxPlates; i >= 0 && j >= 0; i--) {
      if (countsCopy[j] > 0) {
        if (maxPlates - i < 50)
          cout << j;
        countsCopy[j]--;
      }
    }
    cout << endl;
  }

  // last 50 digits of max comb
  countsCopy = counts;
  if (countsCopy[0] == count) {
    cout << 0;
  } else {
    int j = n - 1;
    for (int i = maxPlates; i >= 0 && j >= 0; i--) {
      if (countsCopy[j] > 0) {
        if (i < 49)
          cout << j;
        countsCopy[j]--;
      }
      if (countsCopy[j] == 0)
        j--;
    }
  }
  cout << endl;

  return 0;
}