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
int biggerBucketCount;
int bucketSize;
bool found = false;

bool checkValidComb(bool print = false) {
  int bucketI = 0;
  int currBucket = 0;
  int i = 0;

  // for (int el : bucketCountArr) cout << el << " ";
  // cout << endl;

  while (currBucket < target) {
    int incSize = bucketSize;
    while (bucketI < bucketCountArr.size() &&
           bucketCountArr[bucketI] < currBucket)
      bucketI++;
    if (bucketI < bucketCountArr.size() &&
        bucketCountArr[bucketI] == currBucket)
      incSize++;
    i += incSize;
    if (i >= n) break;
    // cout << "incsize: " << incSize << " i: " << i << " curr: " << currBucket
    //      << endl;

    int upperLimit = arr[i];
    // cout << "upper " << upperLimit << endl;
    if (print) {
      cout << upperLimit << " ";
    } else if (arr[i - 1] >= upperLimit)
      //  (i + 1 < n && arr[i + 1] == upperLimit))
      return false;
    currBucket++;
  }
  return true;
}

void recur(int depth = 0) {
  if (found) return;
  if (bucketCountArr.size() == biggerBucketCount) {
    if (!checkValidComb()) return;
    checkValidComb(true);
    found = true;
    return;
  }

  for (int i = depth; i < target; i++) {
    bucketCountArr.push_back(i);
    recur(i + 1);
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

  // for (int i = 0; i < n; i++) {
  //   cout << arr[i] << " ";
  // }
  // cout << endl << endl;

  bucketSize = floor(n / target);
  biggerBucketCount = n - (bucketSize * target);
  recur(0);

  return 0;
}