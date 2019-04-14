#include <iostream>
#include <cstring>
using namespace std;

void run_program(int *dishes, int *dna) {
	int sum;
	int new_dishes[40];
	for (int i = 0; i < 40; i++) {
		sum = dishes[i];
		if (i != 0) 
			sum += dishes[i-1];
		if (i != 39)
			sum += dishes[i+1];
		new_dishes[i] = dna[sum];
	}
	memcpy(dishes, new_dishes, sizeof(int)*40);
}

int main() {
	int n;
	int dna[10];
	int dishes[40];
	int def_dishes[40] = {0};
	def_dishes[19] = 1;
	int tmp;
	
	char ch_density[4] = {' ', '.', 'x', 'W'};
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		memcpy(dishes, def_dishes, sizeof(int) * 40);
		
		for (int j = 0; j < 10; ++j) {
			cin >> tmp;
			dna[j] = tmp;
		}
		
		for (int j = 0; j < 50; ++j) {
			for (int k = 0; k < 40; ++k) 
				cout << ch_density[dishes[k]];
			cout << endl;
			run_program(dishes, dna);
		}
		if (i < n-1)
			cout << endl;
	}
	
	return 0;
}