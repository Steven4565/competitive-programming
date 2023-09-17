#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  int x;
  cin >> n >> x;

  int lowestDiff = 100000000;
  int winningCoupon = 1000000;

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;

    int diff = abs(input - x);
    if (diff < lowestDiff || (diff == lowestDiff && input < winningCoupon)) {
      winningCoupon = input;
      lowestDiff = diff;
    }
  }
  cout << winningCoupon << endl;

  return 0;
}