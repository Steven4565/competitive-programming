#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<bool>> matrix, int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << matrix[i][j] + 0;
    }
    cout << endl;
  }
  cout << "==================" << endl;
}

bool isFull(vector<bool> array, int length) {
  int rowSum = 0;
  for (int i = 0; i < array.size(); i++) {
    rowSum += array[i] - '0';
  }

  return rowSum == length;
}

void fillCol(vector<vector<bool>>& matrix, int rowStart, int colIdx,
             int count) {
  for (int i = rowStart; i >= 0; i--) {
    if (count > 0) {
      count--;
      matrix[i][colIdx] = true;
    } else {
      matrix[i][colIdx] = false;
    }
  }
}

int main() {
  int row, col;
  cin >> row >> col;
  vector<vector<bool>> matrix(row, vector<bool>(col, false));

  for (int i = 0; i < row; i++) {
    string rowStr;
    cin >> rowStr;

    int rowSum = 0;
    for (int j = 0; j < rowStr.size(); j++) {
      matrix[i][j] = rowStr[j] - '0';
    }
  }

  // Count all the full rows
  while (true) {
    vector<int> rowSum(row, 0);
    vector<int> colSum(col, 0);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        int value = matrix[i][j];
        rowSum[i] += value;
      }
    }

    // cout << "rowsum" << endl;
    // for (int i = 0; i < row; i++) {
    //   cout << rowSum[i] << " ";
    // }
    // cout << endl;

    // Specify which rows are full;
    int fullRows = 0;
    int lowestIdx = -1;
    for (int i = 0; i < row; i++) {
      if (rowSum[i] == col) {
        fullRows++;
        lowestIdx = i;
        for (int j = 0; j < col; j++) {
          matrix[i][j] = false;
        }
      }
    }

    // printMatrix(matrix, row, col);

    if (lowestIdx == -1) {
      break;
    }

    // Count the sum of columns above the lowest full row;
    for (int i = 0; i < col; i++) {
      for (int j = lowestIdx; j >= 0; j--) {
        if (matrix[j][i]) {
          colSum[i]++;
        }
      }
    }

    // for (int i = 0; i < col; i++) {
    //   cout << " " << colSum[i];
    // }
    // cout << endl;

    for (int i = 0; i < col; i++) {
      for (int j = lowestIdx; j < row; j++) {
        if (matrix[j][i]) {
          // cout << "row: " << j << " col: " << i << endl;
          fillCol(matrix, j - 1, i, colSum[i]);
          break;
        } else if (j == row - 1) {
          fillCol(matrix, j, i, colSum[i]);
          // cout << "row: " << j << " col: " << i << endl;
          break;
        }
      }
    }
  }

  // cout << "colsum" << endl;
  // for (int i = 0; i < col; i++) {
  //   cout << i << " " << colSum[i] << " " << endl;
  // }
  // cout << endl;

  // print out the matrix
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << matrix[i][j] + 0;
    }
    cout << endl;
  }

  return 0;
}