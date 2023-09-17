#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Entry {
public:
  string name;
  string number;

  Entry() {
    name = "";
    number = "";
  }

  Entry(string name, string number) {
    name = name;
    number = number;
  }
};

Entry *search(vector<Entry> &entries, string name) {
  int l = 0;
  int r = entries.size() - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (entries[m].name == name) {
      return &entries[m];
    } else if (entries[m].name.compare(name) > 0) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  return NULL;
}

int main() {

  int n, q;
  cin >> n >> q;

  vector<Entry> book(n);
  for (int i = 0; i < n; i++) {
    cin >> book[i].name >> book[i].number;
  }

  for (int i = 0; i < q; i++) {
    string name;
    cin >> name;
    Entry *res = search(book, name);
    if (res)
      cout << res->number << endl;
    else
      cout << "NIHIL" << endl;
  }

  return 0;
}