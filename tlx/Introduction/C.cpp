#include <iostream>
#include <string>
#include <vector>

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

  for (int i = 0; i < n; i++) {
    string word = words[i];
    bool matched = true;

    // the following doesn't work, but it was good practice for 2 pointers
    // anyways int ptrW = 0; int ptrR = 0; while (ptrR <= regex.size() && ptrW
    // <= word.size()) {
    //   if (regex[ptrR] == '*' &&
    //       (ptrR + 1 == regex.size() || word[ptrW] != regex[ptrR + 1])) {
    //     ptrW++;
    //   } else if (regex[ptrR] == word[ptrW]) {
    //     ptrW++;
    //     ptrR++;
    //   } else {
    //     matched = false;
    //     break;
    //   }
    // }

    // if (matched)
    //   cout << word << endl;

    size_t astPos = regex.find("*");
    string startReg = regex.substr(0, astPos);
    string endReg = regex.substr(astPos + 1);

    bool startFlag = false;
    bool endFlag = false;
    if (startReg.size() == 0 || word.find(startReg) == 0) {
      startFlag = true;
      word.erase(0, startReg.size());
    }

    if (endReg.size() == 0 ||
        (word.rfind(endReg) != string::npos &&
         word.rfind(endReg) == word.size() - endReg.size())) {
      endFlag = true;
    }

    if (startFlag && endFlag) {
      cout << words[i] << endl;
    }
  }
  return 0;
}
