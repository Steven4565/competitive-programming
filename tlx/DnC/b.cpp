#include <stdio.h>

#include <algorithm>
#include <cmath>
#include <iostream>
typedef long long ll;

using namespace std;

ll a, b, res;
ll mod = 100000000;
int numCount = 0;
double prevLog, nextLog;

int main() {
  cin >> a >> b;
  res = 1;

  numCount += floor(log10(a));

  while (b > 0) {
    if (b % 2 == 1) {
      res *= a;
      numCount += res / mod;
      res %= mod;
      b--;
    }
    b /= 2;
    prevLog = a == 0 ? 0 : log10(a);
    a *= a;
    nextLog = a == 0 ? 0 : log10(a);

    a %= mod;
    numCount += floor(nextLog) - floor(prevLog);
  }

  res %= 1000000;
  string str = "%0" + to_string(min(numCount, 6)) + "lld\n";

  printf(str.c_str(), res);

  return 0;
}