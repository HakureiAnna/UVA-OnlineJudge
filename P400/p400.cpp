#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_LEN 60

int main() {
  vector<string> lines;
  string line;
  int rows, cols;
  int n;
  int maxLen;
  int numLines;
  bool lastDisplayed;
  int pos;
  int width;

  while (cin >> n) {
    cin.ignore();
    lines.clear();

    maxLen  = 0;
    for (int i = 0; i < n; ++i) {
      getline(cin, line);

      lines.push_back(line);
      if (line.length() > maxLen)
        maxLen = line.length();
    }
    sort(lines.begin(), lines.end());

    numLines = lines.size();
    cols = (MAX_LEN - maxLen) / (maxLen + 2) + 1;
    rows = numLines / cols + (numLines % cols? 1: 0);
    cols = numLines / rows + (numLines % rows? 1: 0);
    //cout << cols << ", " << rows << endl;

    for  (int i = 0; i < MAX_LEN; ++i)
      cout << "-";
    cout << endl;
    lastDisplayed = false;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        pos = i + j * rows;
        if (pos >= (cols-1) * rows)
          width = maxLen;
        else
          width = maxLen + 2;

        if (lastDisplayed && j == cols - 2)
          width = maxLen;

        if (pos < numLines)
          printf("%-*s", width, lines[pos].c_str());
        if (pos == numLines - 1)
          lastDisplayed = true;
      }
      cout << endl;
    }
  }
}
