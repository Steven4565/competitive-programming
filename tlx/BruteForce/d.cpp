#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct move {
  int base;
  char type;
};

int y;

void printMove(struct move m) { cout << m.base << " " << m.type << endl; }

bool calculateDance(vector<struct move> &moves, int threshold) {
  int scoreCount = 0;
  bool meyakinkan = false;
  for (int i = 0; i < moves.size(); i++) {
    int base = moves[i].base;
    if (i >= 0) {
      if (moves[i - 1].type == 'P')
        base *= 2;
      else if (moves[i - 1].type == 'L')
        base /= 2;
    }

    if (meyakinkan)
      base += y;
    if (moves[i].type == 'Y')
      meyakinkan = true;

    scoreCount += base;
  }
  // cout << scoreCount << endl;
  return scoreCount > threshold;
}

int permute(vector<struct move> &moves, int r, int standard, int used,
            vector<struct move> &currentMoves, int currentN) {
  if (currentN > r) {
    // for (int i = 0; i < r; i++) {
    //   printMove(currentMoves[i]);
    // }
    return calculateDance(currentMoves, standard);
    // cout << endl;
  }
  int count = 0;
  for (int i = 0; i < moves.size(); i++) {
    if (0 == (used & (1 << i))) {
      currentMoves[currentN - 1] = moves[i];
      count += permute(moves, r, standard, used | (1 << i), currentMoves,
                       currentN + 1);
    }
  }

  return count;
}

int main() {
  string subquestion;
  int subNumb;
  cin >> subquestion >> subNumb;

  int n, r, j;
  cin >> n >> r >> y >> j;
  vector<struct move> moves(n);
  for (int i = 0; i < n; i++) {
    cin >> moves[i].base >> moves[i].type;
  }

  vector<struct move> current(n);
  for (int i = 0; i < j; i++) {
    int threshold;
    cin >> threshold;
    int res = permute(moves, r, threshold, 0, current, 1);
    cout << res << endl;
  }

  return 0;
}