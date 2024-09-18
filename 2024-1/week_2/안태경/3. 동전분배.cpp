#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int dp(vector<vector<int>>& info, int goal, int index) {
	if (goal == 0) {
		return 1;
	}

	if (goal - info[index][0] >= 0) {
		if (info[index][1] == 1) {
			if (index + 1 == info.size()) return 0;
			return dp(info, goal - info[index][0], index + 1) == 1 ? 1 : 0;
		}
		info[index][1] -= 1;
		return dp(info, goal - info[index][0], index) == 1 ? 1 : 0;
	}
	else {
		if (index + 1 == info.size()) return 0;
		return dp(info, goal, index + 1) == 1 ? 1 : 0;
	}
}

void algorithm(vector<vector<int>>& info) {
	int money = 0;
	for (int i = 0; i < info.size(); i++) {
		money += info[i][0] * info[i][1];
	}
	if (money % 2 != 0) {
		cout << 0 << endl;
		return;
	}
	int goal = money / 2;
	dp(info, goal, 0) == 1 ? cout << 1 << endl : cout << 0 << endl;
}

int main() {
	int count, coin, coin_count;
	
	for (int i = 0; i < 3; i++) {
		cin >> count;
		vector<vector<int>> info(count);
		for (int j = 0; j < count; j++) {
			cin >> coin >> coin_count;
			info[j].push_back(coin);
			info[j].push_back(coin_count);
		}
		algorithm(info);
	}
}
