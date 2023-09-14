#include <bits/stdc++.h>
using namespace std;

int match(string regex, string word, int regI, int wordI) {
  if (regex[regI] == '*') {
    if (wordI == word.size() - 1) {
      // if it's the last character, it's always true
      return true;
    } else {
      // if there's a character after the wildcard, check that first
      return word[wordI + 1] != regex[regI];
    }
  } else {
    return word[wordI] == regex[regI];
  }
}

int main(int argc, char const *argv[]) {
  string regex;
  cin >> regex;

  int n;
  cin >> n;

  vector<string> words(n);
  for (int i = 0; i < n; i++) {
    cin >> words[i];
  }

  bool patternMatches = false;
  int ptrR = -1;
  int ptrW = 0;
  while (true) {
    if (regex[ptrR] == '*') {
    }
  }
  return 0;
}
