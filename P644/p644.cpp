#include <iostream>
#include <string>
using namespace std;

bool repeat(string *codes, int n) {
  int sLen, cLen;
  int iLim = n - 1;
  bool isRepeat;
  for (int i = 0; i < iLim; ++i) {
    sLen = codes[i].length();
    for (int j = i+1; j < n; ++j) {
      cLen = codes[j].length();
      isRepeat = true;
      for (int k  = 0; k < cLen && k < sLen; ++k) {
        if (codes[i][k] != codes[j][k]) {
          isRepeat = false;
          break;
        }
      }
      if (isRepeat)
        return true;
    }
  }
  return false;
}

int main() {
  string codes[20];
  string tmp;
  int i = 0;
  int j = 1;
  bool isRepeat = false;

  while (getline(cin, tmp)) {

    if (tmp[0] == '9') {
      isRepeat = repeat(codes, i);
      cout << "Set " << j++ << " is " <<
        (isRepeat? "not ": "") << "immediately decodable\n";
      i = 0;
      isRepeat = false;
      continue;
    }
    codes[i] = tmp;
    //cout << "i=" << i << endl;
    i++;
  }
  return 0;
}
