#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double dist(int *treeA, int *treeB);

int main() {
  int trees[5000][3];
  int histogram[10] = {0};
  int x, y, z;
  int n = 0;
  double d;
  int nearD;

  while (1) {
    cin >> x >> y >> z;
    if (!x && !y && !z)
      break;
    trees[n][0] = x;
    trees[n][1] = y;
    trees[n][2] = z;
    n++;
  }

  for (int i = 0; i < n; ++i) {
    nearD = 10;
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        d = dist(trees[i], trees[j]);
        if (d < nearD) {
          nearD = (int)d;
        }
      }
    }
    if (nearD < 10)
      histogram[nearD]++;
  }

  for (int i = 0; i < 10; ++i) {
    printf("%4d", histogram[i]);
  }
  printf("\n");

  return 0;
}

double dist(int *treeA, int *treeB) {
  double d = 0;
  for (int i = 0; i < 3; ++i) {
    d += pow(treeA[i] - treeB[i], 2);
  }
  return sqrt(d);
}
