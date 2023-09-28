#include <iostream>
using namespace std;

typedef long long ll;

ll mod = 1000000000, a, b, c;

ll power(ll x, ll y) {
  ll res = 1;
  while (y > 0) {
    if (y % 2 == 1) {
      res *= x;
      res %= mod;
      y--;
    }
    y /= 2;
    x *= x;
    x %= mod;
    // cout << "x " << a << endl;
  }
  return res;
}

int main() {
  // ll mod2;
  cin >> a >> b >> c >> mod;
  for (int i = 0; i < c; i++) {
    a = power(a, b);
    // cout << "a " << a << endl;
  }
  cout << a + 1 << endl;
  return 0;
}