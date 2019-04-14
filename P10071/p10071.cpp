#include <iostream>
#include <cmath>
using namespace std;

int disp(int v, int t) {
	return v * t;
}

int main() {
	int x, y;

	while (cin >> x >> y) {

		cout << 2 * disp(x, y) << endl;
	}

	return 0;
}
