#include <iostream>
#include <map>
using namespace std;


string parsePhone(string phone);

int main() {
  map<string, int> directory;
  int n;
  int numPhones;
  string phone;
  map<string, int>::iterator itor;
  bool duplicate;

  cin >> n;
  cin.ignore();
  getline(cin, phone);



  for (int i = 0; i < n; ++i) {
    getline(cin, phone);
    numPhones = 0;
    for (int j = 0; j < phone.length(); ++j) {
      if (phone[j] < '0' || phone[j] > '9')
        break;
      numPhones *= 10;
      numPhones += phone[j] - '0';
    }
    //cout << numPhones << endl;

    directory.clear();
    duplicate = false;
    for (int j = 0; j < numPhones; ++j) {
      getline(cin, phone);
      //cout << "'" << phone << "'->";
      phone = parsePhone(phone);
      //cout << "'" << phone << "'" << endl;

      itor = directory.find(phone);
      if (itor == directory.end())
        directory.insert(pair<string, int>(phone, 1));
      else {
        itor->second++;
        duplicate = true;
      }
    }

    getline(cin, phone);
    //cout << "'" << phone << "'" << endl;

    if (duplicate) {
      for (itor = directory.begin(); itor != directory.end(); ++itor)
        if (itor->second > 1)
          cout << itor->first << " " << itor->second << endl;
    }
    else
      cout << "No duplicates.\n";
    if (i < n-1)
      cout << endl;
  }

  return 0;
}

string parsePhone(string phone) {
  int sLen = phone.length();
  string nPhone = "--------";
  int j = 0;
  for (int i = 0; i < sLen; ++i) {
    if (phone[i] >= '0' && phone[i] <= '9') {
      nPhone[j++] = phone[i];
    } else if (phone[i] >= 'A' && phone[i] <= 'Z') {
      switch (phone[i]) {
      case 'A':
      case 'B':
      case 'C':
        nPhone[j++] = '2';
        break;
      case 'D':
      case 'E':
      case 'F':
        nPhone[j++] = '3';
        break;
      case 'G':
      case 'H':
      case 'I':
        nPhone[j++] = '4';
        break;
      case 'J':
      case 'K':
      case 'L':
        nPhone[j++] = '5';
        break;
      case 'M':
      case 'N':
      case 'O':
        nPhone[j++] = '6';
        break;
      case 'P':
      case 'R':
      case 'S':
        nPhone[j++] = '7';
        break;
      case 'T':
      case 'U':
      case 'V':
        nPhone[j++] = '8';
        break;
      case 'W':
      case 'X':
      case 'Y':
        nPhone[j++] = '9';
        break;
      }
    }
    if (j == 3)
      ++j;
  }
  return nPhone;
}
