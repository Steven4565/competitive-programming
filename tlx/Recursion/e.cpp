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

void printBound(Bound bound) {
  cout << "x: " << bound.x << ", y: " << bound.y << endl;
  cout << "w: " << bound.w << ", h: " << bound.h << endl;
}

enum types { homogen, contains, nonHomogen };

types checkType(vector<vector<int>> &matrix, Bound bounds) {
  bool homogen = true;
  bool nonHomogen = true;
  cout << "start" << endl;
  for (int i = bounds.y; i < bounds.h + bounds.y; i++) {
    for (int j = bounds.x; j < bounds.w + bounds.x; j++) {
      if (matrix[i][j] == 1)
        nonHomogen = false;
      else
        homogen = true;
    }
  }
  cout << "end" << endl;
  if (homogen)
    return types::homogen;
  else if (nonHomogen)
    return types::nonHomogen;
  else
    return types::contains;
}

void recurse(vector<vector<int>> &matrix, string id, Bound bounds) {
  // split into groups
  int newHeight = bounds.h / 2;
  int newWidth = bounds.w / 2;

  Bound newBounds[4] = {{bounds.x, bounds.y, newWidth, newHeight},
                        {bounds.w / 2, bounds.y, newWidth, newHeight},
                        {bounds.x, bounds.h / 2, newWidth, newHeight},
                        {bounds.w / 2, bounds.h / 2, newWidth, newHeight}};
  for (int i = 0; i < 4; i++) {
    printBound(newBounds[i]);
    cout << i << endl;
    int type = checkType(matrix, newBounds[i]);
    // check if homogen
    if (type == types::homogen) {
      cout << id << i + 1 << endl;
      return;
    } else if (type == types::nonHomogen) {
      return;
    } else {
      recurse(matrix, id + ("" + (i + 1)), newBounds[i]);
    }
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

  recurse(matrix, "0", Bound{0, 0, r, c});

  return 0;
}