#include <iostream>
#include <string>
using namespace std;

char decode(string str);

int main() {
  int i = 0;
  char msg[5000];
  string str;

  getline(cin, str);

  while (getline(cin, str)) {
    if (str[0] != '|')
      continue;
    msg[i++] = decode(str);
  }
  msg[i] = '\0';
  cout << msg;

  return 0;
}

char decode(string str) {
  int ch = 0;
  int lim = str.length() - 1;
  for (int i =1; i < lim; ++i) {
    if (str[i] == '.')
      continue;
    ch <<= 1;
    if (str[i] == 'o')
      ch |= 1;
    else if (str[i] == ' ')
      ch |= 0;
  }
  //cout << ch << endl;
  return char(ch);
}
