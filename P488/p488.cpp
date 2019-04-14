#include <iostream>
using namespace std;

int main() {
	int n;
	int a, f;
	
	cin >> n;
	//cout << n << endl;
	
	// repeat over n sets of no.s
	for (int i = 0; i < n; ++i) {
		cin >> a >> f;
		//cout << a << ", " << f << endl;
		
		if (i > 0) 
			cout << endl;
		
		// repeat of f triangles
		for (int j = 0; j < f; ++j) {
			for (int k = 1; k <= a; ++k) {
				for (int l = 1; l <= k; ++l) {
					cout << k;
				}
				cout << endl;
			}
			for (int k = a-1; k > 0; --k) {
				for (int l = k; l > 0; --l) {
					cout << k;
				}
				cout << endl;				
			}
			if (j < f-1)
				cout << endl;
		}
	}
	
	return 0;
}