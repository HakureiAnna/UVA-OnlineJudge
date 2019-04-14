#include <iostream>
#include <string>
using namespace std;

void judge(int *code, int *guess, int n);

int main() {
  int code[1000];
  int guess[1000];
  bool isZero;
  int n;
  int game = 1;

  while (1) {
      cin >> n;
      if (n == 0)
        break;

      cout << "Game " << game++ << ":\n";
      for (int i = 0; i < n; ++i)
        cin >> code[i];

      while (1) {
        isZero = true;
        for (int i = 0; i < n; ++i) {
          cin >> guess[i];
          if (isZero && guess[i] != 0)
            isZero = false;
        }
        if (isZero)
          break;
        judge(code, guess, n);
      }
  }

  return 0;
}

void judge(int *code, int *guess, int n) {
  bool matchedCode[1000] = {false};
  bool matchedGuess[1000] = {false};
  int strongGuess = 0;
  int weakGuess = 0;

  for (int i = 0; i < n; ++i) {
    if (code[i] == guess[i]) {
      matchedCode[i] = true;
      matchedGuess[i] = true;
      strongGuess++;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (!matchedCode[i]) {
      for (int j = 0; j < n; ++j) {
        if (!matchedGuess[j] && (code[i] == guess[j])) {
          matchedCode[i] = true;
          matchedGuess[j] = true;
          weakGuess++;
          break;
        }
      }
      if (weakGuess + strongGuess == n)
        break;
    }
  }

  cout << "    (" << strongGuess << "," << weakGuess << ")" << endl;
}
