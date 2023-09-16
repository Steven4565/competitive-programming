#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {

  long long a, b, c, d;
  cin >> a >> b >> c >> d;

  long long num, den;
  num = a * d + b * c;
  den = b * d;

  long long gcdRes = gcd(num, den);
  num /= gcdRes;
  den /= gcdRes;

  cout << num << " " << den;

  return 0;
}