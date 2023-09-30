#include <algorithm>
#include <climits>
#include <cmath>
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

  ll remainder = m % leastPrice;
  // cout << "rem " << remainder << endl;
  for (int i = n - 1; i >= 0 && remainder > 0 && maxPlates > 0; i--) {
    // If the previous plate in the sorted array has the same price, then skip.
    // Because it has a lower number.
    if (i - 1 >= 0 && prices[i - 1].second == prices[i].second) continue;

    ll diff = prices[i].second - leastPrice;
    // cout << "diff " << diff << endl;

    // Ran out of plates to swap
    if (counts[prices[0].first] <= 0) break;

    // If it can swap, then swap for the higher plate
    if (diff != 0 && diff <= remainder && remainder != 0) {
      ll bought = remainder / diff;
      remainder %= diff;

      cout << "bought " << bought << endl;

      // cout << "bought " << bought << " " << prices[i].first << endl;
      counts[prices[i].first] += bought;
      counts[prices[0].first] -= bought;  // FIXME: might break if bought more
                                          // upgrades than the current plates.
    }
  }

  // TODO: Another edge case, if the leastPrice is plate 0, then get the other
  // lowest plate to maximize the 0
  if (prices[0].first == 0 && counts[0] == maxPlates && counts[0] > 0 &&
      n > 1 && m >= prices[1].second) {
    // cout << "passed" << endl;
    ll least = ULLONG_MAX;
    for (int i = 0; i < n; i++) {
      if (i == 0) continue;
      least = min(prices[i].second, least);
    }
    // cout << "min " << least << endl;

    ll countReplaced = ceil((double)least / (double)prices[0].second);
    ll moneyCanBeSpent = countReplaced * prices[0].second;
    // cout << "money " << moneyCanBeSpent << endl;
    pair<int, ll> wantedNumber;
    for (int i = 0; i < n; i++) {
      // cout << "pr " << prices[i].first << " " << prices[i].second << endl;
      if (prices[i].first == 0) continue;
      if (prices[i].second <= moneyCanBeSpent) {
        wantedNumber = prices[i];
        // cout << wantedNumber.first << " test" << endl;
        break;
      }
    }
    // cout << "want " << wantedNumber.first << endl;
    counts[0] -= countReplaced;
    counts[wantedNumber.first]++;
  }

  // Edge case, when nothing is bought
  if (maxPlates == 0) {
    cout << maxPlates << endl;
    return 0;
  } else if (maxPlates == counts[0])
    cout << 1 << endl;
  else
    cout << maxPlates << endl;

  // Edgecase, when all the numbers are 0
  if (counts[0] == maxPlates) {
    cout << 0 << endl << 0 << endl;
    return 0;
  }

  vector<ll> countsCopy = counts;
  vector<char> startNum;
  int countsI = n - 1;
  while (countsI >= 0) {
    if (startNum.size() >= 50) break;
    if (countsCopy[countsI] > 0) {
      startNum.push_back('0' + countsI);
      countsCopy[countsI]--;
    }
    while (countsCopy[countsI] <= 0) countsI--;
  }

  vector<char> endNum;
  countsI = 0;
  while (countsI < n) {
    if (endNum.size() >= 50) break;
    if (counts[countsI] > 0) {
      endNum.push_back('0' + countsI);
      counts[countsI]--;
    }
    while (counts[countsI] <= 0) countsI++;
  }

  for (int i = 0; i < startNum.size(); i++) {
    cout << startNum[i];
  }
  cout << endl;
  for (int i = 0; i < endNum.size(); i++) {
    cout << endNum[endNum.size() - 1 - i];
  }
  cout << endl;

  return 0;
}