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

enum types { homogen, contains, nonHomogen };
int fillCount = 0;

void fillBound(vector<vector<int>> &matrix, Bound bound) {
  for (int i = bound.x; i < bound.x + bound.w; i++) {
    for (int j = bound.y; j < bound.y + bound.h; j++) {
      matrix[j][i] = 1;
    }
  }
}

int arrIdx = 0;
void recurse(vector<vector<int>> &matrix, Bound bounds, vector<string> &arr,
             string id) {
  // cout << id << endl;
  if (arr.size() > 0 && arr[arrIdx] == id) {
    fillBound(matrix, bounds);
    arrIdx++;
  }
  if (arrIdx + 1 > arr.size())
    return;
  if (arr[arrIdx].rfind(id, 0) != 0)
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

    recurse(matrix, newBounds[i], arr, newId);
  }
}

int main() {
  int n;
  cin >> n;
  vector<string> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int r, c;
  cin >> r >> c;

  int a = pow(2, ceil(log2(r)));
  int b = pow(2, ceil(log2(c)));
  a = a > b ? a : b;

  vector<vector<int>> matrix(a, vector<int>(a, 0));
  recurse(matrix, Bound{0, 0, a, a}, arr, "1");

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}