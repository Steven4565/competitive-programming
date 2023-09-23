#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
int arr[11000];
vector<int> bucketCountArr;
int target;
int nBucket;

void recur(int depth = 0, int bucketCount = 0) {
  if (depth == n - 1) {
    for (int i = 0; i < bucketCountArr.size(); i++) {
      cout << bucketCountArr[i] << " ";
    }
    cout << endl;
    return;
  }

  for (int i = 0; i < n - (nBucket - bucketCount); i++) {
    bucketCountArr.push_back(nBucket);
    recur(depth + 1, bucketCount + 1);
    bucketCountArr.pop_back();
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cin >> target;

  sort(arr, arr + n);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl << endl;

  nBucket = ceil(n / target);
  recur(0, 0);

  return 0;
}