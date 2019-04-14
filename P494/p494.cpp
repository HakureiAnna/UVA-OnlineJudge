#include <iostream>
#include <string>
using namespace std;

bool isCh(string str, int i) {
	return ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'));
}

int main() {
	string str;
	int words;
	int isWord = 0;

	while (getline(cin, str)) {
			words = 0;
			for (int i = 0; i < str.length(); ++i) {
				if (isCh(str, i)) {
					isWord = 1;
				} else {
					words += isWord;
					isWord = 0;
				}
		}
		cout << words << endl;
	}

	return 0;
}
