#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isFull(vector<bool> array, int length) {
  int rowSum = 0;
  for (int i = 0; i < array.size(); i++) {
    rowSum += array[i] - '0';
  }

  return rowSum == length;
}

using namespace std;

int main() {
  int row, col;

  cin >> row >> col;

  vector<vector<bool>> matrix(row, vector<bool>(col));
  int rowCount[row];

  vector<bool> isRowFull(row);
  for (int i = 0; i < row; i++) {
    string rowStr;
    cin >> rowStr;

    int rowSum = 0;
    for (int j = 0; j < rowStr.size(); j++) {
      matrix[i][j] = rowStr[j] - '0';
      rowSum += rowStr[j] - '0';
    }
    if (rowSum == row) {
      isRowFull[i] = true;
    } else
      isRowFull[i] = false;
  }

  return 0;
}