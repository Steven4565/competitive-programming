#include <bits/stdc++.h>
using namespace std;

class Test {
 public:
  int foo;
  Test(){};
  Test(int a) { foo = a; }
};

int main() {
  vector<Test> tests(10);

  Test bar(5);
  tests[0] = bar;
  cout << tests[0].foo << endl;
}
