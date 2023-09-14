#include <bits/stdc++.h>
using namespace std;

int main() {
  int row, col;

  cin >> row >> col;

  vector<vector<bool>> matrix(row, vector<bool>(col));
  int rowCount[row];

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> matrix[i][j];
      rowCount[i] += matrix[i][j];
    }
  }

  vector<int> emptyRows;
  for (int i = row; i >= 0; i--) {
    if (rowCount[i] == col) {
      for (int j = 0; j < col; j++) {
        matrix[i][j] = false;
        emptyRows.push_back(i);
      }
    }
  }

  return 0;
}