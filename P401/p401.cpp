#include <iostream>
#include <string>
using namespace std;

int isPalindrome(string str);
int isMirroredPalindrome(string str);
char getRev(char c);

int main() {
	string str;
	int isP, isMP;
	string out[4] = {" -- is not a palindrome.\n\n",
					 " -- is a regular palindrome.\n\n",
					 " -- is a mirrored string.\n\n",
					 " -- is a mirrored palindrome.\n\n"};
	while (getline(cin, str)) {
		isP = isPalindrome(str);
		isMP = isMirroredPalindrome(str);
		cout << str << out[(isMP << 1) + isP];
	}
	return 0;
}

int isPalindrome(string str) {
	int i, j;
	i = 0;
	j = str.length() - 1;
	
	
	while (j > i) {
		if (str[i] != str[j])
			return 0;
		i++;
		j--;
	}
	return 1;
}

int isMirroredPalindrome(string str) {
	int i, j;
	char tmp;
	i = 0;
	j = str.length() - 1;
	while (j > i) {
		tmp = getRev(str[i]);
		if (tmp != str[j])
			return 0;
		i++;
		j--;
	}
	
	if (j == i) {
		tmp = getRev(str[i]);
		if (tmp == ' ')
			return 0;
		return 1;
	}
					
	return 1;
}

char getRev(char c) {
	char tmp;
	char ch[36] =  {'A', 'B', 'C', 'D', 'E',
					'F', 'G', 'H', 'I', 'J',
					'K', 'L', 'M', 'N', 'O',
					'P', 'Q', 'R', 'S', 'T',
					'U', 'V', 'W', 'X', 'Y',
					'Z', '1', '2', '3', '4',
					'5', '6', '7', '8', '9'};
	char rev[36] = {'A', ' ', ' ', ' ', '3',
					' ', ' ', 'H', 'I', 'L',
					' ', 'J', 'M', ' ', 'O',
					' ', ' ', ' ', '2', 'T',
					'U', 'V', 'W', 'X', 'Y',
					'5', '1', 'S', 'E', ' ',
					'Z', ' ', ' ', '8', ' '};
	for (int k = 0; k < 36; ++k) 
		if (ch[k] == c) {
				tmp = rev[k];
				break;
		}
	return tmp;
}