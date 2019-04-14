#include <iostream>
#include <string>
using namespace std;

// 1 <= K <= 20, no. of keywords
// 1 <= E <= 20, no. of excuses
// line [2, K+1], keywords
//  (1 <= strlen <= 20)
// line [K+2, K+1+E], excuses
//  [A-Za-z0-9 ".,!?]
//  (1 <= strlen <= 70)
//  at least 1 non-space char
// worst excuse, excuse with largest no. of incidence of keywords
// keyword appear more than once, each appearance counts
// keyword must be delimited by bStr, eStr, nonalphabetical char
// Excuse Set # i
// all worst excuses

void sensitize(string excuse, char *line, int *lineLen);
int countKeywords(char *line, int lineLen, string *keywords, int kLen);

int main() {

  int k, e;
  string keywords[20];
  string excuses[20];
  char line[71];
  int lineLen;
  int counts[20];
  string tmp;
  int maxKey;
  int set = 1;

  while (cin >> k >> e) {
    cin.ignore();
    for (int i = 0; i < k; ++i) {
      getline(cin, tmp);
      keywords[i] = tmp;
    }

    for (int i = 0; i < e; ++i) {
      getline(cin, tmp);
      excuses[i] = tmp;
    }
    maxKey = 0;
    for (int i = 0; i < e; ++i) {
      //cout << "'" << excuses[i] << "'" << endl;
      sensitize(excuses[i], line, &lineLen);
      //cout << "'" << line << "'" << endl;
      counts[i] = countKeywords(line, lineLen, keywords, k);
      //cout << counts[i] << endl;
      if (counts[i] > maxKey)
        maxKey = counts[i];
    }

    cout << "Excuse Set #" << set++ << endl;
    for (int i = 0; i < e; ++i) {
      if (counts[i] == maxKey)
        cout << excuses[i] << endl;
    }
    cout << endl;
  }

  return 0;
}

void sensitize(string excuse, char *line, int *lineLen) {
  int sLen = excuse.length();
  int j = 0;
  bool isAlpha = false;
  for (int i = 0; i < sLen; ++i) {
    if (excuse[i] >= 'A' && excuse[i] <= 'Z') {
      line[j++] = excuse[i] + 'a' - 'A';
      isAlpha = true;
    } else if (excuse[i] >= 'a' && excuse[i] <= 'z') {
      line[j++] = excuse[i];
      isAlpha = true;
    } else {
      if (isAlpha) {
        line[j++] = ' ';
        isAlpha = false;
      }
    }
  }
  if (line[j-1] == ' ') {
    *lineLen = j-1;
    line[j-1] = '\0';
  } else {
    line[j] = '\0';
    *lineLen = j;
  }
}

int countKeywords(char *line, int lineLen, string *keywords, int kLen) {
  int count = 0;
  int sLen;
  bool isKey;
  for (int i = 0; i < kLen; ++i) {
    sLen = keywords[i].length();
    for (int j = 0; j < lineLen; ++j) {
      isKey = true;
      for (int k = 0; k < sLen; ++k) {
        if (line[j] == keywords[i][k]) {
          if (k==sLen-1) {
            if (line[j+1] != ' ' && line[j+1] != '\0') {
              while (j < lineLen && line[j] != ' ')
                ++j;
              isKey = false;
              break;
            }
          }
          ++j;
        } else if (line[j] != keywords[i][k]) {
          //cout << keywords[i] << ": j=" << j << ", k=" << k << endl;
          while (j < lineLen && line[j] != ' ')
            ++j;
          isKey = false;
          break;
        } else {
          isKey = false;
          break;
        }
      }
      if (isKey) {
        cout << "'" << line[j] << "'" << endl;
        if (line[j] == ' ' || line[j] == '\0')
          count++;
        while (j < lineLen && line[j] != ' ')
          ++j;
      }
    }
  }
  return count;
}
