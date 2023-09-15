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

int main() {
  int row, col;
  cin >> row >> col;
  bool matrix[row][col];

  vector<bool> isRowFull(row);
  for (int i = 0; i < row; i++) {
    string rowStr;
    cin >> rowStr;

    int rowSum = 0;
    for (int j = 0; j < rowStr.size(); j++) {
      matrix[i][j] = rowStr[j] - '0';
    }
  }

  vector<int> rowSum(row, 0);
  vector<int> colSum(col, 0);

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int value = matrix[i][j];
      rowSum[i] += value;
      colSum[j] += value;
    }
  }

  int fullRows = 0;
  int lowestIdx = -1;
  for (int i = rowSum.size(); i >= 0; i--) {
    if (rowSum[i] == col) {
      fullRows++;
      lowestIdx = i;
      for (int j = 0; j < col; j++) {
        matrix[i][j] = false;
      }
    }
  }

  for (int i = 0; i < col; i++) {
    for (int j = lowestIdx; j >= 0; j--) {
      if (matrix[j][i]) {
        for (int k = j + 1; k <= colSum[i] - fullRows; k++) {
          matrix[k][i] = true;
        }
      }
    }
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << matrix[i][j] + 0;
    }
    cout << endl;
  }

  return 0;
}