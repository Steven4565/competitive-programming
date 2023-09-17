#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Pair {
  int a;
  int b;
};

void printScores(vector<int> &scores) {
  for (auto score : scores)
    cout << score << " ";
  cout << endl << endl;
}

bool recurse(vector<Pair> &arr, vector<int> scores, int idx,
             vector<int> wanted) {

  if (idx == arr.size()) {
    // printScores(scores);
    if (wanted == scores)
      return true;
    return false;
  }
  scores[arr[idx].a] += 3;
  bool res = recurse(arr, scores, idx + 1, wanted);
  scores[arr[idx].a] -= 3;
  if (res)
    return true;

  scores[arr[idx].b] += 3;
  res = recurse(arr, scores, idx + 1, wanted);
  scores[arr[idx].b] -= 3;
  if (res)
    return true;

  scores[arr[idx].a] += 1;
  scores[arr[idx].b] += 1;
  res = recurse(arr, scores, idx + 1, wanted);
  scores[arr[idx].a] -= 1;
  scores[arr[idx].b] -= 1;
  if (res)
    return true;

  return false;
}

vector<Pair> getCombinations(int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    count += i;
  }
  vector<Pair> pairs(count);
  count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (i == j)
        continue;
      pairs[count] = Pair{i, j};
      count++;
    }
  }
  return pairs;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> scores(n, 0);
    for (int j = 0; j < n; j++) {
      cin >> arr[j];
    }

    vector<Pair> combinations = getCombinations(n);
    int res = recurse(combinations, scores, 0, arr);
    if (res)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}