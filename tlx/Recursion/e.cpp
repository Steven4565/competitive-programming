#include <cmath>
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

int homogenCount = 0;
vector<string> list;
enum types { homogen, contains, nonHomogen };

types checkType(vector<vector<int>> &matrix, Bound bounds) {
  bool homogen = true;
  bool nonHomogen = true;
  for (int i = bounds.y; i < bounds.h + bounds.y; i++) {
    for (int j = bounds.x; j < bounds.w + bounds.x; j++) {
      if (matrix[i][j] == 1)
        nonHomogen = false;
      else
        homogen = false;
    }
  }
  if (homogen)
    return types::homogen;
  else if (nonHomogen)
    return types::nonHomogen;
  else
    return types::contains;
}

void recurse(vector<vector<int>> &matrix, string id, Bound bounds) {
  int type = checkType(matrix, bounds);
  if (type == types::homogen) {
    homogenCount++;
    id[0] = '1';
    list.push_back(id);
    return;
  }
  if (type == types::nonHomogen || (bounds.w == 1 && bounds.h == 1))
    return;

  // split into groups
  int newHeight = bounds.h / 2;
  int newWidth = bounds.w / 2;

  Bound newBounds[4] = {
      {bounds.x, bounds.y, newWidth, newHeight},
      {bounds.x + bounds.w / 2, bounds.y, newWidth, newHeight},
      {bounds.x, bounds.y + bounds.h / 2, newWidth, newHeight},
      {bounds.x + bounds.w / 2, bounds.y + bounds.h / 2, newWidth, newHeight}};
  for (int i = 0; i < 4; i++) {
    string idSuffix = "0";
    idSuffix[0] = idSuffix[0] + i;
    string newId = id + idSuffix;

    recurse(matrix, newId, newBounds[i]);
  }

  return;
}

int main() {
  int r, c;
  cin >> r >> c;

  int n = pow(2, ceil(log2(r)));
  int m = pow(2, ceil(log2(c)));
  n = n > m ? n : m;

  vector<vector<int>> matrix(n, vector<int>(n, 0));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> matrix[i][j];
    }
  }

  recurse(matrix, "0", Bound{0, 0, n, n});
  cout << homogenCount << endl;
  for (auto el : list) {
    cout << el << endl;
  }

  return 0;
}