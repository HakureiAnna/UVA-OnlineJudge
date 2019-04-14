#include <iostream>
#include <string>
using namespace std;

int judge(string solution, string answer) {
	int strokes = 0;
	bool struck;
	bool win;
	
	for (int i = 0; i < answer.length()-1; ++i)
		for (int j = i+1; j < answer.length(); ++j)
			if (answer[i] == answer[j])
				answer[j] = '*';
			
	for (int i = 0; i < answer.length(); ++i) {
		struck = false;
		if (answer[i] == '*')
			continue;
		for (int j = 0; j < solution.length(); ++j) {
			if (answer[i] == solution[j]) {
				solution[j] = '*';
				struck = true;
			}
		}
		if (!struck) {
			strokes++;
			if (strokes == 7)
				return 0;
		}
		win = true;
		for (int k = 0; k < solution.length(); ++k)
			if (solution[k] != '*') {
				win = false;
				break;
			}
		if (win)
			return 1;
	}
	return 2;
}

int main() {
	int round;
	string solution;
	string answer;
	string out[] = {"You lose.\n", "You win.\n", "You chickened out.\n"};
	
	while (1) {
		cin >> round;
		if (round == -1)
			break;
		cin.ignore();
		getline(cin, solution);
		getline(cin, answer);
		cout << "Round " << round << endl;
		cout << out[judge(solution, answer)];
	}
	return 0;
}