#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> matrix(30, vector<int>(30));
int R, C;
int k, n;
int ballCount = 0;
int maxBallCount = 0;
int maxI, maxJ;

void remove(vector<vector<bool>> &visited, int r, int c, int target) {
  if (r < 0 || r >= R || c < 0 || c >= C)
    return;
  if (visited[r][c])
    return;
  if (matrix[r][c] != target)
    return;
  if (matrix[r][c] == target) {
    matrix[r][c] = -1;
    visited[r][c] = true;
  }

  remove(visited, r + 1, c, target);
  remove(visited, r - 1, c, target);
  remove(visited, r, c + 1, target);
  remove(visited, r, c - 1, target);
}

void floodFill(vector<vector<bool>> &visited, int r, int c, int target) {
  if (r < 0 || r >= R || c < 0 || c >= C)
    return;
  if (visited[r][c])
    return;
  if (matrix[r][c] != target)
    return;
  // cout << visited[c][r] << endl;
  if (matrix[r][c] == target) {
    ballCount++;
    visited[r][c] = true;
  }

  floodFill(visited, r + 1, c, target);
  floodFill(visited, r - 1, c, target);
  floodFill(visited, r, c + 1, target);
  floodFill(visited, r, c - 1, target);
}

void swap(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}

void collapse() {
  for (int j = 0; j < C; j++) {
    int lastEmpty = -1;
    for (int i = R - 1; i >= 0; i--) {
      // cout << matrix[i][j] << endl;
      if (matrix[i][j] == -1) {
        if (lastEmpty == -1)
          lastEmpty = i;
        // cout << "saved " << endl;
      } else if (lastEmpty != -1) {
        // cout << "Swapped" << endl;
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

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      vector<vector<bool>> visited(30, vector<bool>(30, false));

      ballCount = 0;
      floodFill(visited, i, j, matrix[i][j]);
      if (ballCount > maxBallCount) {
        maxBallCount = ballCount;
        maxI = i;
        maxJ = j;
      }
    }
  }

  vector<vector<bool>> visited(30, vector<bool>(30, false));
  remove(visited, maxI, maxJ, matrix[maxI][maxJ]);
  collapse();

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (matrix[i][j] == -1)
        cout << ".";
      else
        cout << matrix[i][j];
      cout << " ";
    }
    cout << endl;
  }

  return 0;
}