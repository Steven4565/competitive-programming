#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> matrix(30, vector<int>(30));
vector<vector<int>> visited(30, vector<int>(30, 0));
int R, C;
int k, n;
int ballCount = 0;
int maxBallCount2 = 0;
int maxBallCount = 0;
int maxI, maxJ;

void fillVisited(vector<vector<int>> &visited, int r, int c, int ballCount) {
  if (r < 0 || r >= R || c < 0 || c >= C) return;
  if (visited[r][c] != -1) return;
  visited[r][c] = ballCount;

  fillVisited(visited, r + 1, c, ballCount);
  fillVisited(visited, r - 1, c, ballCount);
  fillVisited(visited, r, c + 1, ballCount);
  fillVisited(visited, r, c - 1, ballCount);
}

void removeMatrix(vector<vector<int>> &matrix, vector<vector<int>> &visited,
                  int r, int c, int target) {
  if (r < 0 || r >= R || c < 0 || c >= C) return;
  if (visited[r][c]) return;
  if (matrix[r][c] != target) return;
  if (matrix[r][c] == target) {
    matrix[r][c] = -1;
    visited[r][c] = ballCount;
  }

  removeMatrix(matrix, visited, r + 1, c, target);
  removeMatrix(matrix, visited, r - 1, c, target);
  removeMatrix(matrix, visited, r, c + 1, target);
  removeMatrix(matrix, visited, r, c - 1, target);
}

int floodFill(vector<vector<int>> &matrix, vector<vector<int>> &visited, int r,
              int c, int target, bool removeCell) {
  if (r < 0 || r >= R || c < 0 || c >= C) return 0;
  if (visited[r][c] != 0) return 0;
  if (matrix[r][c] != target) return 0;

  if (removeCell) matrix[r][c] = -1;
  visited[r][c] = -1;

  int count = 1;

  count += floodFill(matrix, visited, r + 1, c, target, removeCell);
  count += floodFill(matrix, visited, r - 1, c, target, removeCell);
  count += floodFill(matrix, visited, r, c + 1, target, removeCell);
  count += floodFill(matrix, visited, r, c - 1, target, removeCell);

  return count;
}

void printMatrix(vector<vector<int>> &matrix) {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (matrix[i][j] == -1)
        cout << ".";
      else
        cout << matrix[i][j];
    }
    cout << endl;
  }
}

void swap(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}

void collapse(vector<vector<int>> &matrix) {
  for (int j = 0; j < C; j++) {
    int lastEmpty = -1;
    for (int i = R - 1; i >= 0; i--) {
      if (matrix[i][j] == -1) {
        if (lastEmpty == -1) lastEmpty = i;
      } else if (lastEmpty != -1) {
        swap(matrix[i][j], matrix[lastEmpty][j]);
        i = lastEmpty;
        lastEmpty = -1;
      }
    }
    cout << endl;
  }
}

int main() {
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> matrix[i][j];
    }
  }

  int maxScore = 0;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (visited[i][j]) continue;
      vector<vector<int>> matrixCopy = matrix;

      // sets the targets to -1, sets visited to -1
      ballCount = floodFill(matrixCopy, visited, i, j, matrix[i][j], true);
      // sets the -1 visited to ballCount
      fillVisited(visited, i, j, ballCount);
      // collapses the matrix
      collapse(matrixCopy);

      // cout << "copy" << endl;
      // printMatrix(matrixCopy);
      // cout << endl;

      maxBallCount2 = 0;

      // do another loop through the entire matrix.
      for (int l = 0; l < R; l++) {
        for (int m = 0; m < C; m++) {
          if (matrixCopy[l][m] == -1) continue;

          // need a new visited map because it has been collapsed
          vector<vector<int>> visited2(30, vector<int>(30, 0));
          int ballCount2 =
              floodFill(matrixCopy, visited2, l, m, matrixCopy[l][m], false);
          if (ballCount2 > maxBallCount2) maxBallCount2 = ballCount2;
        }
      }
      int score =
          ballCount * (ballCount - 1) + maxBallCount2 * (maxBallCount2 - 1);
      if (score > maxScore) maxScore = score;
    }
  }

  // cout << "visited matrix" << endl;
  // printMatrix(visited);

  // cout << "matrix" << endl;
  // printMatrix(matrix);

  // cout << endl << maxBallCount << endl;
  // cout << endl << maxBallCount2 << endl;

  cout << maxScore << endl;

  return 0;
}