#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long MAX, MIN;

int cutting(vector<long long> start, long long MIN) {
	int result = 0;
	for (long long LAN : start) {
		result += LAN / MIN;
	}
	return result;
}

void algorithm(int n, int goal, vector<long long> start) {
	MAX = *max_element(start.begin(), start.end());
	MIN = MAX / 2;
	if (MIN == 0) {
		cout << 1 << endl;
		return;
	}
	if (cutting(start, MIN) >= goal) {
		while (true){
			if (cutting(start, (MAX + MIN) / 2) >= goal) {
				MIN = (MAX + MIN) / 2;
				if (MIN == (MAX + MIN) / 2) break;
			}
			else {
				MAX = (MAX + MIN) / 2;
			}
		}
		if (cutting(start, MIN + 1) >= goal)
			cout << MIN + 1 << endl;
		else
			cout << MIN << endl;
	}
	else {
		int i = 2;
		while (true) {
			i++;
			MIN = *max_element(start.begin(), start.end()) / i;
			if (cutting(start, MIN) >= goal) break;
		}
		while (true) {
			if (cutting(start, (MAX + MIN) / 2) >= goal) {
				MIN = (MAX + MIN) / 2;
				if (MIN == (MAX + MIN) / 2) break;
			}
			else {
				MAX = (MAX + MIN) / 2;
			}
		}
		if (cutting(start, MIN + 1) >= goal)
			cout << MIN + 1 << endl;
		else
			cout << MIN << endl;

	}
}
int main() {
	int n, goal;
	cin >> n >> goal;

	vector<long long> start;
	for (int i = 0; i < n; i++) {
		long long length;
		cin >> length;
		start.push_back(length);
	}

	algorithm(n, goal, start);
}

