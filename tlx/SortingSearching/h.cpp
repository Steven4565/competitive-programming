#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct Bag {
  int weight;
  int price;
  double pricePerKg;
};

int compare(Bag a, Bag b) { return a.pricePerKg > b.pricePerKg; }

int main() {
  int n, x;
  cin >> n >> x;

  vector<Bag> list(n);
  for (int i = 0; i < n; i++) {
    cin >> list[i].weight;
  }
  for (int i = 0; i < n; i++) {
    cin >> list[i].price;
    list[i].pricePerKg = (double)list[i].price / (double)list[i].weight;
  }

  sort(list.begin(), list.end(), compare);

  int accWeight = 0;
  double accPrice = 0;

  for (int i = 0; i < n; i++) {
    if (accWeight >= x)
      break;

    if (list[i].weight <= x - accWeight) {
      accPrice += list[i].price;
      accWeight += list[i].weight;
    } else {
      int takenWeight = (x - accWeight);
      accPrice += list[i].price * takenWeight / (double)list[i].weight;
      accWeight += takenWeight;
    }
  }

  printf("%.05f\n", accPrice);

  return 0;
}