#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  int matrix[n][m];

  int ansX = -1, ansY = -1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int res = 1;
      if (i > 0)
        res *= matrix[i - 1][j];
      if (i < n - 1)
        res *= matrix[i + 1][j];
      if (j > 0)
        res *= matrix[i][j - 1];
      if (j < m - 1)
        res *= matrix[i][j + 1];

      // cout << "i" << i << "  j" << j << "  " << res << endl;
      if (res == k) {
        if (ansX == -1) {
          ansX = j;
          ansY = i;
          // cout << ansX + 1 << " " << ansY + 1 << endl;
        } else if (j < ansX || (j == ansX && i < ansY)) {
          ansX = j;
          ansY = i;
          // cout << ansX + 1 << " " << ansY + 1 << endl;
        }
      }
    }
  }

  cout << ansY + 1 << " " << ansX + 1 << endl;

  return 0;
}