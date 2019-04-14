#include <iostream>
using namespace std;

int main() {
	int n;
	int sum;
	int tmp;
	int jLim;
	int x, y;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		sum = 0;
		cin >> jLim;
		for (int j = 0; j < jLim; ++j) {
			for (int k = 0; k < 3; ++k) {
				cin >> tmp;
				if (k == 0)
					x = tmp;
				else if (k == 2)
					y = tmp;
			}
			sum += x * y;
		}
		cout << sum << endl;
	}

	return 0;
}
