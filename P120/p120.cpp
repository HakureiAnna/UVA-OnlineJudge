#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void flip(int *pancakes, int from);
int locateBig(int *pancakes, int n);
bool inOrder(int *pancakes, int n);

void print(int *pancakes, int n) {
  for (int i = 0; i < n; ++i)
    cout << pancakes[i] << (i < n-1?" ":"");
  cout << endl;
}
int main() {
  string line;
  stringstream ss;
  int pancakes[30];
  int pancake;
  int n;
  int bigId;
  int flipId;
  int i;
  int curN;
  while (getline(cin, line)) {
    n = 0;
    ss = stringstream(line);
    while (ss >> pancake)
      pancakes[n++] = pancake;

    //i = 0;
    print(pancakes, n);
    curN = n;
    while (!inOrder(pancakes, n)) {
      bigId = locateBig(pancakes, curN);
      cout << n - bigId << " ";
      flip(pancakes, bigId);
      flip(pancakes, --curN);
      cout << n - curN << " ";
      /*
      bigId = locateBig(pancakes, n-i);
      if (bigId) {
        flip(pancakes, n, bigId);
        cout << n - bigId << " ";
      }
      else {
        flip(pancakes, n, n - i - 1);
        ++i;
        cout << i << " ";
      }
      */
    }

    cout << "0\n";

  }

  return 0;
}

void flip(int *pancakes, int from) {
  int i = 0;
  int tmp;
  while (i < from) {
    tmp = pancakes[i];
    pancakes[i] = pancakes[from];
    pancakes[from] = tmp;
    ++i;
    --from;
  }
}

int locateBig(int *pancakes, int n) {
  int max = 0;
  int id = 0;
  for (int i = 0; i < n; ++i) {
    if (pancakes[i] > max) {
      max = pancakes[i];
      id = i;
    }
  }
  return id;
}

bool inOrder(int *pancakes, int n) {
  int iLim = n - 1;
  for (int i = 0; i < iLim; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (pancakes[i] > pancakes[j])
        return false;
    }
  }
  return true;
}
