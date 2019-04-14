#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

void computeP(double vU, double pU, double vI, double pI);
void computeU(double vP, double pP, double vI, double pI);
void computeI(double vP, double pP, double vU, double pU);

bool processP(string str, int *pI, bool *pF, int *pV, int *pP);
bool processU(string str, int *pI, bool *pF, int *pV, int *pP);
bool processI(string str, int *pI, bool *pF, int *pV, int *pP);

bool processHeader(string str, char unit, int *i);
int processPrefix(string str, int lim);
void processValue(string str, int iBeg, int iEnd, int *v, int *p);

int main() {
	int n;
	string str;
	bool fP = false, fU = false, fI = false;
	int pP = 0, pU = 0, pI = 0;
	int vP = 0, vU = 0, vI = 0;
	int sLen;
	int oldJ;
	
	cin >> n;
	cin.ignore();
	
	for (int i = 0; i < n; ++i) {
		fP = false;
		fU = false;
		fI = false;
		getline(cin, str);
		
		sLen = str.length();
		for (int j = 0; j < sLen; ++j) {
			if (!fP && str[j] == 'P') {
				if (processP(str, &j, &fP, &vP, &pP))
					continue;
			} else if (!fU && str[j] == 'U') {
				if (processU(str, &j, &fU, &vU, &pU))
					continue;
			} else if (!fI && str[j] == 'I') {
				if (processI(str, &j, &fI, &vI, &pI))
					continue;
			}
		}
		
		printf("Problem #%d\n", i+1);
		if (fU && fI) 
			computeP(vU, pU, vI, pI);
		if (fP && fI) 
			computeU(vP, pP, vI, pI);
		if (fP && fU)
			computeI(vP, pP, vU, pU);
		printf("\n");
	}

	return 0;
}

// P = U * I
void computeP(double vU, double pU, double vI, double pI) {
	double vP = vU * vI * pow(10, pU + pI);
	
	printf("P=%.2lfW\n", vP);
}

// U = P / I
void computeU(double vP, double pP, double vI, double pI) {
	double vU = vP / vI * pow(10, pP - pI);
	printf("U=%.2lfV\n", vU);
}

// I = P / U
void computeI(double vP, double pP, double vU, double pU) {
	double vI = vP / vU * pow(10, pP - pU);
	printf("I=%.2lfA\n", vI);
}

bool processP(string str, int *pI, bool *pF, int *pV, int *pP) {
	int p = 0;
	int v = 0;
	int j = *pI+1;
	
	if (!processHeader(str, 'W', &j))
		return false;
	
	p = processPrefix(str, j);
	
	processValue(str, *pI+2, (p>0? j-1:j), &v, &p);
	
	*pI = j+1;
	*pF = true;
	*pV = v;
	*pP = p;
	return true;
}

bool processU(string str, int *pI, bool *pF, int *pV, int *pP) {
	int p = 0;
	int v = 0;
	int j = *pI+1;
	
	if (!processHeader(str, 'V', &j))
		return false;
	
	p = processPrefix(str, j);
	
	processValue(str, *pI+2, (p>0? j-1:j), &v, &p);
	
	*pI = j+1;
	*pF = true;
	*pV = v;
	*pP = p;
	return true;
}

bool processI(string str, int *pI, bool *pF, int *pV, int *pP) {
	int p = 0;
	int v = 0;
	int j = *pI+1;
	
	if (!processHeader(str, 'A', &j))
		return false;
	
	p = processPrefix(str, j);
	
	processValue(str, *pI+2, (p>0? j-1:j), &v, &p);
	
	*pI = j+1;
	*pF = true;
	*pV = v;
	*pP = p;
	return true;
}
bool processHeader(string str, char unit, int *i) {
	int sLen;
	int j = *i;
	sLen = str.length();
	if (j < sLen && str[j] != '=')
		return false;
	for (j++; j < sLen; ++j) {
		if (str[j] == unit) {
			*i = j;
			return true;
		}
	}
	return false;
}

int processPrefix(string str, int lim) {	
	--lim;
	if (str[lim] == 'm')
		return -3;
	else if (str[lim] == 'k')
		return 3;
	else if (str[lim] == 'M')
		return 6;
	return 0;
}

void processValue(string str, int iBeg, int iEnd, int *v, int *p) {
	int val = 0;
	int pow = *p;
	bool isDec = false;
	for (int i = iBeg; i < iEnd; ++i) {
		if (str[i] >= '0' && str[i] <= '9') {
			val *= 10;
			val += str[i] - '0';
			if (isDec) {
				pow--;
			}
		} else if (str[i] == '.') {
			isDec = true;
		}
	}
	*v = val;
	*p = pow;
}