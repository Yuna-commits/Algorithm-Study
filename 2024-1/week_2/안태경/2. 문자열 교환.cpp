#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int Count_a(string line, int index, int size) {
	int b_count = 0;
	for (int i = 0; i < size; i++) {
		if (line[index] == 'b') {
			b_count++;
		}
		index++;
		if (index == line.size()) index = 0;
	}
	return b_count;
}

void algorithm(string line, int count) {
	int MIN = 500;
	for (int i = 0; i < line.size(); i++) {
		MIN = min(MIN, Count_a(line, i, count));
	}
	cout << MIN;
}

int main() {
	string line;
	cin >> line;

	int count = 0;
	for (char alphabet : line) {
		if (alphabet == 'a') count++;
	}

	algorithm(line, count);
}
