#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> matrix(30, vector<int>(30));
vector<vector<bool>> visited(30, vector<bool>(30, false));
int R, C;
int k, n;
int ballCount = 0;

void floodFill(int r, int c, int target) {

  // cout << matrix[r][c] << endl;
  // cout << r << " " << c << endl;
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

  floodFill(r + 1, c, target);
  floodFill(r - 1, c, target);
  floodFill(r, c + 1, target);
  floodFill(r, c - 1, target);
}

int main() {
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> matrix[i][j];
    }
  }

  cin >> k >> n;
  floodFill(k, n, matrix[k][n]);

  cout << ballCount * (ballCount - 1) << endl;

  return 0;
}