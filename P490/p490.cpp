#include <iostream>
#include <string>
using namespace std;

int main() {
	string lines[100];
	string out[100];
	string inp;
	int n = 0;
	int maxLen = 0;
	while (getline(cin, inp)) {
		lines[n] = inp;
		if (inp.length() > maxLen)
			maxLen = inp.length();
		n++;
	}
	//cout << "maxLen=" << maxLen << endl;
	//cout << "n=" << n << endl;
	for (int i=0; i < maxLen; ++i) 
		out[i] = string(maxLen, ' ');
	
	for (int i=0; i < maxLen; ++i) {
		for (int j=n-1; j >= 0; --j) {
			if (i < lines[j].length())
				out[i][n-1-j] = lines[j][i]; 
		}
	}
	
	for (int i = 0; i < maxLen; ++i)
		cout << out[i] << endl;
	
	return 0;
}