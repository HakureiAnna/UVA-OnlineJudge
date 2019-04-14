#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  string dict[10][2];
  string line;
  string tmp;
  int pos;
  bool replace;

  while (1) {
    cin >> n;
    if (!n)
      break;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 2; ++j) {
        getline(cin, tmp);
        dict[i][j] = tmp;
      }
    }
    getline(cin, line);

    for (int i = 0; i < n; ++i) {
        replace = true;
        while (replace) {
          replace = false;
          //cout << "needle=" << dict[i][0] << endl;
          pos = line.find(dict[i][0]);
          //cout << (pos == string::npos? "not found": "found") << endl;
          if (pos != string::npos) {
            //cout << "bef: " << line << endl;
            line = line.replace(pos, dict[i][0].length(), dict[i][1]);
            //cout << "aft: " << line << endl;
            replace = true;
          }
        }
    }
    cout << line << endl;
  }
  return 0;
}
