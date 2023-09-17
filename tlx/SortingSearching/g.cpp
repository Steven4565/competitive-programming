#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int compare(double a, double b) { return a > b; }

int main() {
  int n;
  cin >> n;
  double arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n, compare);

  double ans;
  if (n % 2 == 0) {
    printf("%.01f\n", (arr[n / 2] + arr[n / 2 - 1]) / 2);
  } else {
    printf("%.01f\n", arr[n / 2]);
  }

  return 0;
}