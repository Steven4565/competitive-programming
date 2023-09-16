#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long long maxNum = 1000000;
long long maxN = 77777;

bool primes[maxNum];

int main() {
  for (int i = 0; i < maxNum; i++)
    primes[i] = true;

  int t;
  cin >> t;

  vector<long long> primesRes;

  for (long long i = 2; i * i < maxNum; i++) {
    if (primes[i]) {
      for (long long j = i * i; j < maxNum; j += i) {
        primes[j] = false;
      }
    }
  }

  for (int i = 2; i < maxNum; i++) {
    if (primes[i]) {
      primesRes.push_back(i);
    }
  }

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    cout << primesRes[n - 1] << endl;
  }

  return 0;
}