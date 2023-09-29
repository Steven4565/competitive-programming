#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int n, b;
int arr[20001];
int minCount = INT_MAX;

// void solve(int idx, int sum, int count) {
//   if (idx >= n || sum > b || count > minCount)
//     return;
//   if (sum == b)
//     minCount = min(count, minCount);

//   for (int i = idx; i < n; i++) {
//     // cout << i << endl;
//     solve(i + 1, sum + arr[i], count + 1);
//   }
// }

int main() {
  cin >> n >> b;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr, arr + n);
  int sum = 0;
  int count = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (sum >= b)
      break;
    count++;
    sum += arr[i];
  }

  // solve(0, 0, 0);

  cout << count << endl;

  return 0;
}