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

  // Get max number of plates you can buy
  ll leastPrice = prices[0].second;
  counts[prices[0].first] = m / leastPrice;
  ll maxPlates = m / leastPrice;

  // TODO: Another edge case, if the leastPrice is plate 0, then get the other
  // lowest plate to maximize the 0 if (prices[0].first == 0) {

  // }

  ll remainder = m % leastPrice;
  // cout << "rem " << remainder << endl;
  for (int i = n - 1; i >= 0 && remainder > 0 && maxPlates > 0; i--) {
    // If the previous plate in the sorted array has the same price, then skip.
    // Because it has a lower number.
    if (i - 1 >= 0 && prices[i - 1].second == prices[i].second)
      continue;

    ll diff = prices[i].second - leastPrice;
    // cout << "diff " << diff << endl;

    // Ran out of plates to swap
    if (counts[prices[0].first] <= 0)
      break;

    // If it can swap, then swap for the higher plate
    if (diff != 0 && diff <= remainder && remainder != 0) {
      ll bought = remainder / diff;
      remainder %= diff;
      // cout << "bought " << bought << " " << prices[i].first << endl;
      counts[prices[i].first] += bought;
      counts[prices[0].first] -= bought; // FIXME: might break if bought more
                                         // upgrades than the current plates.
    }
  }

  // Edge case, when nothing is bought
  if (maxPlates == 0) {
    cout << maxPlates << endl;
    return 0;
  } else if (maxPlates == counts[0])
    cout << 1 << endl;
  else
    cout << maxPlates << endl;

  vector<char> startNum, endNum;

  if (counts[0] == maxPlates) {
    cout << 0 << endl << 0 << endl;
    return 0;
  } else {
    int plateNum = n - 1;
    // FIXME: This is O(n), fix this.
    for (int i = maxPlates; i >= 0 && plateNum >= 0; i--) {
      if (counts[plateNum] > 0) {
        bool startPush = false, endPush = false;
        if (startNum.size() < 50) {
          startNum.push_back('0' + plateNum);
          startPush = true;
          // cout << "num" << plateNum << endl;
        }
        if (i <= 50) {
          endNum.push_back('0' + plateNum);
          endPush = true;
        }

        if (!endPush && !startPush) {
          cout << "i bef " << i << endl;
          i -= counts[plateNum] - 1;
          cout << "i after " << i << endl;
          counts[plateNum] = 0;
        } else
          counts[plateNum]--;
      }
      while (counts[plateNum] == 0) {
        plateNum--;
      }
    }
  }
  // cout << "Size " << startNum.size() << endl;
  for (int i = 0; i < startNum.size(); i++) {
    cout << startNum[i];
  }
  cout << endl;
  for (int i = 0; i < endNum.size(); i++) {
    cout << endNum[i];
  }
  cout << endl;

  return 0;
}