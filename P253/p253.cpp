#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define DEBUG 1

bool compare(string boxA, string boxB) {
	int patterns[24][6] = {
		{0, 1, 3, 4, 2, 5},
		{0, 3, 4, 2, 1, 5},
		{0, 4, 2, 1, 3, 5},
		{0, 2, 1, 3, 4, 5},
		{1, 5, 3, 0, 2, 4},
		{1, 3, 0, 2, 5, 4},
		{1, 0, 2, 5, 3, 4},
		{1, 2, 5, 3, 0, 4},
		{2, 1, 0, 4, 5, 3}, 
		{2, 0, 4, 5, 1, 3},
		{2, 4, 5, 1, 0, 3},
		{2, 5, 1, 0, 4, 3},  
		{3, 1, 5, 4, 0, 2},
		{3, 5, 4, 0, 1, 2}, 
		{3, 4, 0, 1, 5, 2},
		{3, 0, 1, 5, 4, 2},
		{4, 0, 3, 5, 2, 1},
		{4, 3, 5, 2, 0, 1},
		{4, 5, 2, 0, 3, 1},
		{4, 2, 0, 3, 5, 1},
		{5, 4, 3, 1, 2, 0},
		{5, 3, 1, 2, 4, 0},
		{5, 1, 2, 4, 3, 0},
		{5, 2, 4, 3, 1, 0}};	

	char patA[7] = {'\0'},
		 patB[7] = {'\0'};
		  
	for (int i = 0; i < 6; ++i) 
		patA[i] = boxA[patterns[0][i]];
	
	for (int i = 0; i < 24; ++i) {
		for (int j = 0; j < 6; ++j)
			patB[j] = boxB[patterns[i][j]];
		if (!strcmp(patA, patB)) 
			return true;
	}
	return false;
}

int main() {
	string line, boxA, boxB;
		 
	while (getline(cin, line)) {
		boxA = line.substr(0, 6);
		boxB = line.substr(6);
		cout << (compare(boxA, boxB)? "TRUE": "FALSE") << endl;
	}
	return 0;
}
