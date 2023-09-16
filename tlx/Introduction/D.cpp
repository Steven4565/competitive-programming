#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

void correct() { cout << "Tentu saja bisa!" << endl; }

void wrong() { cout << "Wah, tidak bisa :(" << endl; }

int main() {
  string a, b;
  cin >> a >> b;

  int aLen = a.size();
  int bLen = b.size();

  if (abs(aLen - bLen) != 1) {
    wrong();
    return 0;
  }

  int i = 0, j = 0;
  while (true) {
    if (a[i] != b[j]) {
      if (aLen > bLen) {
        a.erase(i, 1);
      } else {
        b.erase(i, 1);
      }
      break;
    }
    i++;
    j++;
  }

  if (a == b)
    correct();
  else
    wrong();

  return 0;
}