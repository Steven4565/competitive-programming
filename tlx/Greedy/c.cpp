#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
ll comp(ll a, ll b) { return a > b; }

ll n;
ll arr[10001], arr2[10001];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  for (int i = 0; i < n; i++)
    cin >> arr2[i];

  sort(arr, arr + n);
  sort(arr2, arr2 + n, comp);
  ll sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i] * arr2[i];
  cout << sum << endl;
  return 0;
}