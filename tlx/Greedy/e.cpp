#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

ll n, b;
ll ducks[2000];
ll shoes[2000];

bool checkI(int d, int s) {
  if (ducks[d] == shoes[s] || ducks[d] == shoes[s] - 1)
    return true;
  return false;
}

signed main() {
  cin >> b >> n;
  for (int i = 0; i < b; i++)
    cin >> ducks[i];
  for (int i = 0; i < n; i++)
    cin >> shoes[i];

  sort(ducks, ducks + b);
  sort(shoes, shoes + n);

  ll duckI = 0, shoesI = 0;
  ll count = 0;
  while (duckI < b && shoesI < n) {
    if (checkI(duckI, shoesI)) {
      count++;
      duckI++;
      shoesI++;
    } else if (shoes[shoesI] < ducks[duckI])
      shoesI++;
    else
      duckI++;
  }

  cout << count << endl;

  return 0;
}