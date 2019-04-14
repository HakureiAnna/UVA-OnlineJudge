#include <iostream>
#include <string>
using namespace std;

string toLower(string str);
bool walkDiagRD(string *grid, string word, int grid_m, int grid_n, int i, int j);
bool walkDiagLU(string *grid, string word, int grid_m, int grid_n, int i, int j);
bool walkDiagLD(string *grid, string word, int grid_m, int grid_n, int i, int j);
bool walkDiagRU(string *grid, string word, int grid_m, int grid_n, int i, int j);
bool walkHorL(string *grid, string word, int grid_m, int grid_n, int i, int j);
bool walkHorR(string *grid, string word, int grid_m, int grid_n, int i, int j);
bool walkVertU(string *grid, string word, int grid_m, int grid_n, int i, int j);
bool walkvertD(string *grid, string word, int grid_m, int grid_n, int i, int j);
void findWords(string *grid, string *words, int grid_m, int grid_n, int words_n);
bool findWord(string *grid, string word, int grid_m, int grid_n, int i, int j);
void print(int i, int j);


int main() {
	int n;
	int grid_m, grid_n;
	int words_n;
	string grid[50];
	string words[20];
	string tmp;
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> grid_m >> grid_n;
		cin.ignore();
		for (int j = 0; j < grid_m; ++j) {
			getline(cin, tmp);
			grid[j] = toLower(tmp);
			//cout << grid[j] << endl;
		}
		cin >> words_n;
		cin.ignore();
		for (int j = 0; j < words_n; ++j) {
			getline(cin, tmp);
			words[j] = toLower(tmp);
			//cout << words[j] << endl;
		}
		findWords(grid, words, grid_m, grid_n, words_n);
		if (i < n-1)
			cout << endl;
	}
	return 0;
}

string toLower(string str) {
	for (int i = 0; i < str.length(); ++i)
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
	return str;
}

bool walkDiagRD(string *grid, string word, int grid_m, int grid_n, int i, int j) {
	int k = 0;
	int iLim = i + word.length();
	for (; i < iLim; ++i) {
		if (grid[i][j] != word[k]) {
			//cout << " RD: word[" << k << "]=" << word[k] << ", grid[" <<  i << "][" << j << "]=" << grid[i][j] <<  ", i=" << i << ", j=" << j << ", k=" << k << endl;
			return false;
		}
		j++;
		k++;
		if (k == word.length()) {
			return true;
		}
	}
	return false;
}

bool walkDiagLU(string *grid, string word, int grid_m, int grid_n, int i, int j) {	
	int k = 0;
	int iLim = i - word.length();
	for (; i > iLim; --i) {
		if (grid[i][j] != word[k]) {
			//cout << " LU: word[" << k << "]=" << word[k] << ", grid[" <<  i << "][" << j << "]=" << grid[i][j] <<  ", i=" << i << ", j=" << j << ", k=" << k << endl;
			return false;
		}
		j--;
		k++;
		if (k == word.length()) {
			return true;
		}
	}
	return false;
}

bool walkDiagLD(string *grid, string word, int grid_m, int grid_n, int i, int j) {	
	int k = 0;
	int iLim = i + word.length();
	for (; i < iLim; ++i) {
		if (grid[i][j] != word[k]) {
			//cout << " LD: word[" << k << "]=" << word[k] << ", grid[" <<  i << "][" << j << "]=" << grid[i][j] <<  ", i=" << i << ", j=" << j << ", k=" << k << endl;
			return false;
		}
		j--;
		k++;
		if (k == word.length()) {
			return true;
		}
	}
	return false;
}

bool walkDiagRU(string *grid, string word, int grid_m, int grid_n, int i, int j) {	int k = 0;
	int iLim = i - word.length();
	for (; i > iLim; --i) {
		if (grid[i][j] != word[k]) {
			//cout << " RU: word[" << k << "]=" << word[k] << ", grid[" <<  i << "][" << j << "]=" << grid[i][j] <<  ", i=" << i << ", j=" << j << ", k=" << k << endl;
			return false;
		}
		j++;
		k++;
		if (k == word.length()) {
			return true;
		}
	}
	return false;
}

bool walkHorL(string *grid, string word, int grid_m, int grid_n, int i, int j) {
	int k = 0;
	int jLim = j - word.length();
	for (; j > jLim; --j) {
		if (grid[i][j] != word[k])
			return false;
		k++;
		if (k == word.length())
			return true;
	}
	return false;
}

bool walkHorR(string *grid, string word, int grid_m, int grid_n, int i, int j) {
	int k = 0;
	int jLim = j + word.length();
	for (; j < jLim; ++j) {
		if (grid[i][j] != word[k])
			return false;
		k++;
		if (k == word.length())
			return true;
	}
	return false;
}

bool walkVertU(string *grid, string word, int grid_m, int grid_n, int i, int j) {
	int k = 0;
	int iLim = i - word.length();
	for (; i > iLim; --i) {
		if (grid[i][j] != word[k])
			return false;
		k++;
		if (k == word.length())
			return true;
	}
	return false;
}

bool walkVertD(string *grid, string word, int grid_m, int grid_n, int i, int j) {
	int k = 0;
	int iLim = i + word.length();
	for (; i < iLim; ++i) {
		if (grid[i][j] != word[k])
			return false;
		k++;
		if (k == word.length())
			return true;
	}
	return false;
}

void findWords(string *grid, string *words, int grid_m, int grid_n, int words_n) {
	bool found;
	for (int i = 0; i < words_n; ++i) {
		found = false;
		for (int j = 0; j < grid_m; ++j) {
			for (int k = 0; k < grid_n; ++k) {
				found = findWord(grid, words[i], grid_m, grid_n, j, k);
				if (found)
					break;
			}
			if (found)
				break;
		}
	}
}	

bool findWord(string *grid, string word, int grid_m, int grid_n, int i, int j) {
	bool vL, vR, vU, vD;
	int wordLen;
	
	wordLen = word.length();
	// j <= grid_n - wordLen			# valid for right
	vR = (j <= grid_n - wordLen);
	// i <= grid_m - wordLen			# valid for down
	vD = (i <= grid_m - wordLen);
	// j >= wordLen - 1					# valid for left
	vL = (j >= wordLen - 1);
	// i >= wordLen - 1					# valid for up
	vU = (i >= wordLen - 1);
	//cout << "word=" << word << ", i=" << i << ", " << "j=" << j << ",R=" << vR << ", L=" << vL << ", U=" << vU << ", D=" << vD << endl;
	if (vR && vD) 
		if (walkDiagRD(grid, word, grid_m, grid_n, i, j)) {
			print(i, j);
			return true;
		}
	if (vL && vU)
		if (walkDiagLU(grid, word, grid_m, grid_n, i, j)) {
			print(i, j);
			return true;
		}
	if (vL && vD)
		if (walkDiagLD(grid, word, grid_m, grid_n, i, j)) {
			print(i, j);
			return true;
		}
	if (vR && vU)
		if (walkDiagRU(grid, word, grid_m, grid_n, i, j)) {
			print(i, j);
			return true;
		}
	if (vL)
		if (walkHorL(grid, word, grid_m, grid_n, i, j)) {
			print(i, j);
			return true;
		}
	if (vR)
		if (walkHorR(grid, word, grid_m, grid_n, i, j)) {
			print(i, j);
			return true;
		}
	if (vU)
		if (walkVertU(grid, word, grid_m, grid_n, i, j)) {
			print(i, j);
			return true;
		}
	if (vD)
		if (walkVertD(grid, word, grid_m, grid_n, i, j)) {
			print(i, j);
			return true;
		}
		
	return false;
}

void print(int i, int j) {
	cout << (i+1) << " " << (j+1) << endl;
}