#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

struct move {
  ll base;
  char type;
};

ll y;

void printMove(struct move m) { cout << m.base << " " << m.type << endl; }

bool calculateDance(vector<struct move> &moves, ll threshold) {
  ll scoreCount = 0;
  bool meyakinkan = false;
  for (ll i = 0; i < moves.size(); i++) {
    ll base = moves[i].base;
    // cout << "base prev " << base << endl;
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
    // cout << "base after" << base << endl;
    scoreCount += base;
  }
  // cout << scoreCount << endl;
  return scoreCount > threshold;
}

ll permute(vector<struct move> &moves, ll r, ll standard, ll used,
           vector<struct move> &currentMoves, ll currentN) {
  if (currentN > r) {
    return calculateDance(currentMoves, standard);
  }
  ll count = 0;
  for (ll i = 0; i < moves.size(); i++) {
    if (0 == (used & (1 << i))) {
      currentMoves[currentN - 1] = moves[i];
      count += permute(moves, r, standard, used | (1 << i), currentMoves,
                       currentN + 1);
    }
  }

  return count;
}

signed main() {
  string subquestion;
  ll subNumb;
  cin >> subquestion >> subNumb;

  ll n, r, j;
  cin >> n >> r >> y >> j;
  vector<struct move> moves(n);
  for (ll i = 0; i < n; i++) {
    cin >> moves[i].base >> moves[i].type;
  }

  vector<struct move> current(n);
  for (ll i = 0; i < j; i++) {
    ll threshold;
    cin >> threshold;
    ll res = permute(moves, r, threshold, 0, current, 1);
    cout << res << endl;
  }

  // calculateDance(moves, 62);

  return 0;
}