#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Bound {
  int x;
  int y;
  int w;
  int h;
};

enum types { homogen, contains, nonHomogen };

types checkType(vector<vector<int>> &matrix, Bound bounds) {
  bool homogen = true;
  bool nonHomogen = true;
  for (int i = bounds.y; i < bounds.h; i++) {
    for (int j = bounds.x; j < bounds.w; i++) {
      if (matrix[i][j] == 1)
        nonHomogen = false;
      else
        homogen = true;
    }
  }
  if (homogen)
    return types::homogen;
  else if (nonHomogen)
    return types::nonHomogen;
  else
    return types::contains;
}

void recurse(string id, Bound bounds) {
  // split into groups
  for (int i = 0; i < 4; i++) {
    // check if homogen
    // if homogen, print
    // if contains, recurse
  }

  return;
}

int main() {
  int r, c;
  cin >> r >> c;

  vector<vector<int>> matrix(r, vector<int>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> matrix[i][j];
    }
  }

  recurse("0", Bound{0, 0, r, c});

  return 0;
}