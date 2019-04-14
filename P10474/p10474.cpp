#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, q;
  vector<int> marbles;
  int num;
  int j;
  int caseNo = 1;

  while (1) {
    cin >> n >> q;
    if (!n && !q)
      break;

    cout << "CASE# " << caseNo++ << ":\n";

    marbles.clear();
    for (int i = 0; i < n; ++i) {
      cin >> num;
      marbles.push_back(num);
    }
    sort(marbles.begin(), marbles.end());
    for (int i = 0; i < q; ++i) {
      cin >> num;

      j = 0;
      for (vector<int>::iterator itor = marbles.begin(); itor != marbles.end(); ++itor) {
        if (*itor == num) {
          break;
        }
        j++;
      }

      if (j < marbles.size())
        cout << num << " found at " << j+1 << endl;
      else
        cout << num << " not found\n";
    }
  }
  return 0;
}
