#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sub(int x, int y, vector<vector<int>>& sharks) {
	int MIN = 100;
	for (vector<int> shark : sharks) {
		int sub1, sub2;
		shark[0] > x ? sub1 = shark[0] - x : sub1 = x - shark[0];
		shark[1] > y ? sub2 = shark[1] - y : sub2 = y - shark[1];
		int sub = max(sub1, sub2);
		MIN = min(MIN, sub);
	}
	return MIN;
}

int main() {
	int column, row;
	cin >> column >> row;
	vector<vector<int>> square(column, vector<int>(row, 0));
	vector<vector<int>> sharks;
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			cin >> square[i][j];
			if (square[i][j] == 1) {
				sharks.push_back({ i, j });
			}
		}
	}
	int MAX = 0;
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			MAX = max(MAX, sub(i, j, sharks));
		}
	}
	cout << MAX;
}

