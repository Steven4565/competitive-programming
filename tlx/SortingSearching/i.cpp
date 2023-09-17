#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int compare(int a, int b) { return a < b; }

int main() {
  int n;
  int wantedIdx;
  cin >> n >> wantedIdx;

  int heights[n];
  for (int i = 0; i < n; i++) {
    cin >> heights[i];
  }

  sort(heights, heights + n, compare);

  cout << heights[wantedIdx - 1];

  return 0;
}