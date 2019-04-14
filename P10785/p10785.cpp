#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Letter {
  char letter;
  int count;
};

void resetLetters(vector<Letter> *letters, char *characters, int n, int count);
char getLetter(vector<Letter> *letters);
char getCharacter(map<char, int> *letters);

int main() {
  char consonantLetters[] = {'J', 'S', 'B', 'K', 'T',
                             'C', 'L', 'D', 'M', 'V',
                             'N', 'W', 'F', 'X', 'G',
                             'P', 'Y', 'H', 'Q', 'Z',
                             'R'};
  int consonantCount = 5;
  char vowelLetters[] = {'A', 'U', 'E', 'O', 'I'};
  int vowelCount = 21;
  vector<Letter> consonants;
  vector<Letter> vowels;
  map<char, int> usedVowels;
  map<char, int> usedConsonants;
  map<char, int>::iterator itor;
  char ch;
  int n, m;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    resetLetters(&consonants, consonantLetters, 21, consonantCount);
    resetLetters(&vowels, vowelLetters, 5, vowelCount);
    usedVowels.clear();
    usedConsonants.clear();

    cin >> m;
    cout << "Case " << i+1 << ": ";
    for (int j = 0; j < m; ++j) {
      if (j % 2) {
        ch = getLetter(&consonants);
        //cout << ch << endl;
        itor = usedConsonants.find(ch);
        if (itor == usedConsonants.end())
          usedConsonants.insert(pair<char, int>(ch, 1));
        else
          itor->second++;
      } else {
        ch = getLetter(&vowels);
        //cout << ch << endl;
        itor = usedVowels.find(ch);
        if (itor == usedVowels.end())
          usedVowels.insert(pair<char, int>(ch, 1));
        else
          itor->second++;
      }
    }
    for (int j = 0; j < m; ++j)
      cout << getCharacter((j%2? &usedConsonants: &usedVowels));
    cout << endl;
  }
  return 0;
}

void resetLetters(vector<Letter> *letters, char *characters, int n, int count) {
  Letter letter;
  letters->clear();
  for (int i = 0; i < n; ++i) {
    letter.letter = characters[i];
    letter.count = count;
    letters->push_back(letter);
  }
}

char getLetter(vector<Letter> *letters) {
  for (vector<Letter>::iterator itor = letters->begin(); itor!= letters->end(); ++itor)
    if (itor->count) {
      itor->count--;
      return itor->letter;
    }
    return '\0';
}

char getCharacter(map<char, int> *letters) {
  for (map<char, int>::iterator itor = letters->begin(); itor!= letters->end(); ++itor) {
    //cout << itor->first << endl;
    if (itor->second) {
      itor->second--;
      return itor->first;
    }
  }
  return '\0';
}
