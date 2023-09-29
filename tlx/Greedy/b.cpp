#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
pair<int, int> windows[100001];

int comp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int compFirst(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> windows[i].first;
    int input;
    cin >> input;
    windows[i].second = windows[i].first + input;
  }

  sort(windows, windows + n, comp);

  int count = 0;
  int startTime = 0;
  for (int i = 0; i < n; i++) {
    if (windows[i].first >= startTime) {
      startTime = windows[i].second;
      // cout << startTime << " " << windows[i].second << endl;
      count++;
    }
  }
  cout << count << endl;

  return 0;
}