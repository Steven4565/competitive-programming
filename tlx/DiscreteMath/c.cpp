#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

int main() {
  int n;
  cin >> n;

  int ans = -1;
  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    if (ans == -1) {
      ans = input;
    } else {
      ans = lcm(ans, input);
    }
  }

  cout << ans << endl;

  return 0;
}