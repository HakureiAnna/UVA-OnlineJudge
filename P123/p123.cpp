#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

struct SortTerm {
  string keyword;
  int i;
  int pos;
};

void printTitlesByKeyword(vector<SortTerm> *sortTerms, vector<string> *titles);
void putTermsByKeyword(vector<SortTerm> *sortTerms, vector<string> *forbidden, string line, int id);
bool compare(SortTerm a, SortTerm b);

int main() {
  vector<string> forbidden;
  vector<string> titles;
  vector<SortTerm> sortTerms;
  string line;
  int i = 0;

  while (getline(cin, line)) {
    if (line == "::")
      break;
      forbidden.push_back(line);
  }

  while (getline(cin, line)) {
    titles.push_back(line);
    putTermsByKeyword(&sortTerms, &forbidden, line, i++);
  }

  sort(sortTerms.begin(), sortTerms.end(), compare);
  printTitlesByKeyword(&sortTerms, &titles);
  //for (vector<SortTerm>::iterator itor = sortTerms.begin(); itor != sortTerms.end(); ++itor)
    //cout << itor->keyword << endl;
  //printList(&forbidden);
  //cout << "::\n";
  //printList(&titles);


  return 0;
}

void putTermsByKeyword(vector<SortTerm> *sortTerms, vector<string> *forbidden, string line, int id) {
  char word[11];
  int i, j = 0, start = 0;
  vector<string>::iterator itor;
  SortTerm sortTerm;
  bool prevBlank = (line[0] == ' '? true: false);
  for (int i = 0; i < line.length(); ++i) {
    if (line[i] == ' ') {
      if (j) {
        word[j] = '\0';
        j = 0;
        prevBlank = true;
        itor = find(forbidden->begin(), forbidden->end(), string(word));
        if (itor == forbidden->end()) {
          //cout << word << endl;
          sortTerm.keyword = string(word);
          sortTerm.i = id;
          sortTerm.pos = start;
          sortTerms->push_back(sortTerm);
        }
      }
      continue;
    }
    if (prevBlank) {
      start = i;
      prevBlank = false;
    }
    word[j++] = (islower(line[i])? line[i]: tolower(line[i]));
  }
  if (j) {
    word[j] = '\0';
    itor = find(forbidden->begin(), forbidden->end(), string(word));
    if (itor == forbidden->end()) {
      //cout << word << endl;
      sortTerm.keyword = string(word);
      sortTerm.i = id;
      sortTerm.pos = start;
      sortTerms->push_back(sortTerm);
    }
  }
}

void printTitlesByKeyword(vector<SortTerm> *sortTerms, vector<string> *titles) {
  bool inKeyword;
  string title;
  int sLen;
  for (vector<SortTerm>::iterator itor = sortTerms->begin(); itor != sortTerms->end(); ++itor) {
    inKeyword = false;
    title = (*titles)[itor->i];
    sLen = title.length();
    //cout << itor->pos << endl;
    for (int i = 0; i < sLen; ++i) {
      if (i == itor->pos) {
        cout << (char)toupper(title[i]);
        inKeyword = true;
      } else if (inKeyword) {
        if (title[i] == ' ') {
          cout << ' ';
          inKeyword = false;
        } else
          cout << (char)toupper(title[i]);
      } else {
        cout << (char)tolower(title[i]);
      }
    }
    cout << endl;
  }
}

bool compare(SortTerm a, SortTerm b) {
  return (a.keyword == b.keyword && ((a.i == b.i && a.pos < b.pos) || a.i < b.i))
   || a.keyword < b.keyword;
}
