#include <iostream>
using namespace std;

int main() {
	long long a, l;
	int i = 1;
	int terms;
	int outA;
	while (1) {
		cin >> a >> l;
		if (a < 0)
			break;
		terms = 1;
		outA = a;
		while (a!=1) {			
			if (a%2)
				a = 3 * a+1;
			else 
				a >>= 1;
			if (a > l)
				break;
			terms++;
		}
		
		cout << "Case " << i << ": A = " << outA << ", limit = " << l 
			<< ", number of terms = " << terms << endl;
		i++;
	}
	return 0;
}