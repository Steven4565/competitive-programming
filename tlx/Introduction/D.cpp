#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

void correct() { cout << "Tentu saja bisa!" << endl; }

void wrong() { cout << "Wah, tidak bisa :(" << endl; }

int main() {
  string a, b;
  cin >> a >> b;

  int i = 0, j = 0;
  int diffIdx;
  bool skipped = false;
  bool valid = true;
  while (true) {
    if (a[i] != b[j]) {
      if (!skipped)
        skipped = true;
      else {
        valid = false;
      }

      if (a.size() > b.size()) {
        i++;
      } else {
        j++;
      }
    } else {
      j++;
      i++;
    }
  }
  // cout << diffIdxEnd << endl << diffIdxStart << endl;
  if (valid && skipped) {
    correct();
  } else {
    wrong();
  }

  return 0;
}