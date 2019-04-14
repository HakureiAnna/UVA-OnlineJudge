#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
  map<string, int> lovers;
  int n;
  string line;
  string country;
  map<string, int>::iterator itor;
  int j;

  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; ++i) {
    getline(cin, line);
    //cout << "'" << line << "'" << endl;
    for (j = 0; j < line.length(); ++j) {
      if (line[j] != ' ')
        break;
    }
    //cout << "'" << line << "'" << endl;
    line = line.substr(j);
    //cout << "'" << line << "'" << endl;
    country = line.substr(0, line.find(" "));
    //cout << "'" << country << "'" << endl;

    itor = lovers.find(country);
    if (itor != lovers.end()) {
      itor->second += 1;
    } else {
        lovers.insert(pair<string, int>(country, 1));
    }
  }

  for (itor = lovers.begin(); itor != lovers.end(); ++itor) {
    cout << itor->first << " " << itor->second << endl;
  }

  return 0;
}
