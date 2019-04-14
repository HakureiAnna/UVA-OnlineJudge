#include <iostream>
using namespace std;

int main() {
  int n;
  int l;
  int carriages[50];
  int swaps;
  int jLim;
  int tmp;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> l;
    for (int j = 0; j < l; ++j) {
      cin >> carriages[j];
    }

    swaps = 0;
    jLim = l - 1;
    for (int j = 0; j < jLim; ++j)
      for (int k = j+1; k < l; ++k)
        if (carriages[k] < carriages[j]) {
          tmp = carriages[k];
          carriages[k] = carriages[j];
          carriages[j] = tmp;
          swaps++;
        }
    cout << "Optimal train swapping takes " << swaps << " swaps.\n";
  }

  return 0;
}
