#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isOkay(vector<char>& password) {
	vector<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
	int vowel_count = 0, consonant_count = 0;

	for (char code : password) {
		if (find(vowels.begin(), vowels.end(), code) == vowels.end()) {
			consonant_count++;
		}
		else vowel_count++;
	}

	return (vowel_count >= 1 && consonant_count >= 2);
}

void algorithm(int length, vector<char>& clues, int current, vector<char>& password) {
	if (password.size() == length) {
		if (isOkay(password)) {
			for (char code : password) cout << code;
			cout << '\n';
		}
		return;
	}
	for (int i = current; i < clues.size(); i++) {
		password.push_back(clues[i]);
		algorithm(length, clues, i + 1, password);
		password.pop_back();
	}
}

int main() {
	int length, clue_count;
	cin >> length >> clue_count;

	vector<char> clues;
	for (int i = 0; i < clue_count; i++) {
		char clue;
		cin >> clue;
		clues.push_back(clue);
	}
	sort(clues.begin(), clues.end());
	vector<char> password;

	algorithm(length, clues, 0, password);

	return 0;
}
