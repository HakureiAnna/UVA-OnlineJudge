#include <iostream>
#include <string>
#include <cctype>
#include <set>
using namespace std;

void parseLine(string line, string *words, int *n);
void removeAnagramsBuildSet(set<string> *ananagrams, string *words, int n);
void buildSet(set<string> *ananagrams, string *words, int n);
bool compare(string wordA, string wordB);
void printWords(set<string> *ananagrams);

int main() {
  string words[2000];
  string line;
  set<string> ananagrams;
  int n = 0;

  while (getline(cin, line)) {
    if (line.length() == 1 && line[0] == '#')
      break;
    parseLine(line, words, &n);
  }
  removeAnagramsBuildSet(&ananagrams, words, n);
  printWords(&ananagrams);

  return 0;
}

void parseLine(string line, string *words, int *n) {
  int i = *n;
  int k = 0;
  char word[21];
  int sLen = line.length();

  for (int j = 0; j < sLen; ++j) {
    if (line[j] == ' ') {
      if (k > 0) {
        word[k] = '\0';
        words[i++] = string(word);
        k = 0;
      }
      continue;
    }
    word[k++] = line[j];
  }
  if (k > 0) {
    word[k] = '\0';
    words[i++] = string(word);
  }
  *n = i;
}

void removeAnagramsBuildSet(set<string> *ananagrams, string *words, int n) {
  int iLim = n - 1;
  int sLen;
  bool isAnagram;
  int i, j;
  for (i = 0; i < iLim; ++i) {
    if (!words[i].length())
      continue;
    sLen = words[i].length();
    isAnagram = false;
    for (j = i + 1; j < n; ++j) {
      if (words[j].length() == sLen && compare(words[i], words[j])) {
        isAnagram = true;
        words[j] = "";
      }
    }
    if (isAnagram) {
      words[i] = "";
    }
    else
      ananagrams->insert(words[i]);
  }
  if (words[n-1].length() != 0)
    ananagrams->insert(words[n-1]);
}

bool compare(string wordA, string wordB) {
  bool found[20] = {false};
  int sLen = wordA.length();
  int valA, valB;
  bool isFound;
  for (int i = 0; i < sLen; ++i) {
    valA = wordA[i] - (isupper(wordA[i])? 'A': 'a');
    isFound = false;
    for (int j = 0; j < sLen; ++j) {
      if (!found[j]) {
        valB = wordB[j] - (isupper(wordB[j])? 'A': 'a');
        if (valA == valB) {
          found[j] = true;
          isFound = true;
          break;
        }
      }
    }
    if (!isFound)
      return false;
  }
  return true;
}

void printWords(set<string> *ananagrams) {
  for (set<string>::iterator itor = ananagrams->begin();
    itor != ananagrams->end(); ++itor)
    cout << *itor << endl;
}
