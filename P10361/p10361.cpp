#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	int n;
	char s[5][101];
	char line1[201];
	char line2[201];
	string l1, l2;
	int phase;
	int sLen;
	int j, k, l;
	int order[4] = {3, 2, 1, 4};
	
	cin >> n;
	cin.ignore();
	
	for (int i = 0; i < n; ++i) {
		getline(cin, l1);
		getline(cin, l2);
		
		phase = 0;
		sLen = l1.length();
		k = 0;
		l = 0;
		for (j = 0; j < sLen; ++j) {
			if ((!(phase%2) && l1[j] == '<') || 
				(phase%2 && l1[j] == '>')) {
				s[phase][k] = '\0';
				phase++;
				k = 0;
				continue;
			}
			line1[l] = l1[j];
			s[phase][k] = l1[j];
			k++;
			l++;
		}
		line1[l] = '\0';
		s[4][k] = '\0';
		
		sLen = l2.length() - 3;
		for (j = 0; j < sLen; ++j) {
			line2[j] = l2[j];
		}
		for (k = 0; k < 4; ++k) {
			sLen = strlen(s[order[k]]);
			for (l = 0; l < sLen; ++l) {
				line2[j] = s[order[k]][l];
				j++;
			}
		}
		line2[j] = '\0';
		
		cout << line1 << endl;
		cout << line2 << endl;
	}
	return 0;
}