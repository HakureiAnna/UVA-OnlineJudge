#include <iostream>
using namespace std;

int a3np1(int n) {
	int cnt = 1;
	while (n != 1) {
		if (n % 2)
			n = 3*n + 1;
		else 
			n /= 2;
		cnt++;
	}
	return cnt;
}

int main() {
	int inX, inY;
	int ordX, ordY;
	int maxVal, curVal;
	int i;
	
	while (cin >> inX >> inY) {
		ordX = (inX > inY? inY: inX);
		ordY = (inX > inY? inX: inY);
		maxVal = a3np1(ordX);
		
		for (i = ordX + 1; i <= ordY; ++i) {
			curVal = a3np1(i);
			maxVal = (curVal > maxVal? curVal: maxVal);
		}
		cout << inX << " " << inY << " " << maxVal << endl;
	}
	return 0;
}