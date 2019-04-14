#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int sum;
	
	while (getline(cin, str)) {
		if (!str.length()) {
			cout << endl;
			continue;
		}
		sum = 0;
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] >= '0' && str[i] <= '9') {
				sum += str[i] - '0';
			} else if (str[i] == 'b') {
				for (int j = 0; j < sum; ++j) {
					cout << ' ';
				}
				sum = 0;
			} else if ((str[i] >= 'A' && str[i] <= 'Z') || str[i] == '*') {
				for (int j = 0; j < sum; ++j) {
					cout << str[i];
				}
				sum = 0;
			} else if (str[i] == '!') {
				cout << endl;
			}
		}
		cout << endl;
	}
	
	return 0;
}