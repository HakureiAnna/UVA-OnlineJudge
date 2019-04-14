
#include <set>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string line;
  set<string> dict;
  string current;
  int sLen;
  char ch;

   while (getline(cin, line)) {
    sLen = line.length();
    current = "";
    for (int i = 0; i < sLen; ++i) {
      ch = tolower(line[i]);
      if (islower(ch))
        current += ch;
      else if (current != "") {
        dict.insert(current);
        current = "";
      }
    }
    if (current != "")
      dict.insert(current);
  }

  for (set<string>::iterator itor = dict.begin(); itor != dict.end(); ++itor)
    cout << *itor << endl;

  return 0;
}
