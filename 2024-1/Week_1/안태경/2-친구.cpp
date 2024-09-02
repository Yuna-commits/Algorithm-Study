#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;

void algorithm(int people, vector<string>& start) {
	vector<set<int>> friend_count(people );
	for (int i = 0; i < people; i++) {
		for (int j = 0; j < people; j++) {
			if (start[i][j] == 'Y') friend_count[i].insert(j);
		}
	}
	vector<set<int>> temp = friend_count;
	for (int i = 0; i < people; i++) {
		for (int friends : temp[i]) {
			for (int f_f : temp[friends]) {
				friend_count[i].insert(f_f);
			}
		}
	}
	int result = 0;
	for (int i = 0; i < people; i++) {
		result = max(result, (int)friend_count[i].size() - 1);
	}
	cout << result;
}

int main() {
	int people;
	cin >> people;

	vector<string> start;
	for (int i = 0; i < people; i++) {
		string BOOL;
		cin >> BOOL;
		start.push_back(BOOL);
	}
	 
	algorithm(people, start);
	return 0;
}
