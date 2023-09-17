#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  //
  int n;
  cin >> n >> n;

  vector<vector<int>> mat(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }

  cin >> n >> n;
  vector<vector<int>> mat2(n, vector<int>(n));

  bool identical = true;
  bool vertical = true;
  bool horizontal = true;
  bool leftBottom = true;
  bool rightBottom = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat2[i][j];
      if (mat[i][j] != mat2[i][j])
        identical = false;
      if (mat[i][n - j - 1] != mat2[i][j])
        vertical = false;
      if (mat[n - i - 1][j] != mat2[i][j])
        horizontal = false;
      if (mat[n - j - 1][n - i - 1] != mat2[i][j])
        leftBottom = false;
      if (mat[j][i] != mat2[i][j])
        rightBottom = false;
    }
  }

  if (identical)
    cout << "identik" << endl;
  else if (vertical)
    cout << "vertikal" << endl;
  else if (horizontal)
    cout << "horisontal" << endl;
  else if (leftBottom)
    cout << "diagonal kiri bawah" << endl;
  else if (rightBottom)
    cout << "diagonal kanan bawah" << endl;
  else
    cout << "tidak identik" << endl;

  // // reflect vertical
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     cout << mat[i][n - j - 1];
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  // // reflect horizontal
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     cout << mat[n - i - 1][j];
  //   }
  //   cout << endl;
  // }

  // cout << endl;

  // // reflect diagonal kiri bawah
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     cout << mat[n - j - 1][n - i - 1];
  //   }
  //   cout << endl;
  // }

  // cout << endl;
  // // reflect diagonal kanan bawah
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     cout << mat[j][i];
  //   }
  //   cout << endl;
  // }

  return 0;
}