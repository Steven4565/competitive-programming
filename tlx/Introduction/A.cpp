#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Score {
public:
  string id;
  int score1, score2, score3;

  Score(){};
  Score(string id, int x, int y, int z)
      : id(id), score1(x), score2(y), score3(z){};

  void print() {
    cout << id << " " << score1 << " " << score2 << " " << score3 << endl;
  }
};

bool compare(Score a, Score b) {
  if (a.score3 != b.score3) {
    return a.score3 > b.score3;
  } else if (a.score2 != b.score2) {
    return a.score2 > b.score2;
  } else if (a.score1 != b.score1) {
    return a.score1 > b.score1;
  } else
    return false;
}

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n, allowedPass;
    string wantedId;
    cin >> n >> allowedPass;
    cin >> wantedId;

    vector<Score> scores;

    while (n--) {
      string id;
      int score1, score2, score3;
      cin >> id;
      cin >> score1;
      cin >> score2;
      cin >> score3;

      Score score(id, score1, score2, score3);
      scores.push_back(score);
    }

    sort(scores.begin(), scores.end(), compare);

    for (int i = 0; i < scores.size(); i++) {
      if (scores[i].id == wantedId) {
        // cout << i;
        if (i < allowedPass) {
          cout << "YA" << endl;
        } else {
          cout << "TIDAK" << endl;
        }
        break;
      }
    }
  }
  return 0;
}
