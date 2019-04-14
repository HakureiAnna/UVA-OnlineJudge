#include <iostream>
#include <string>
#include <climits>
using namespace std;

int dist(string s) {
	int i;
	int blanks = 0;
	for (i = 0; i < 25; ++i)
		if (s[i] == ' ')
			blanks++;
	return blanks;
}

int main() {
	int n;
	string str;
	int dists[13];
	int minDist;
	int sum;
	while (cin >> n) {
		if (n == 0)
			break;
		cin.ignore();
		minDist = 25;
		for (int i = 0; i < n; ++i) {
			getline(cin, str);
			dists[i] = dist(str);
			//cout << dists[i] << endl;
			if (dists[i] < minDist) {
				minDist = dists[i];
			}
		}
		sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += dists[i] - minDist;
		}
		cout << sum << endl;
	}

	return 0;
}
