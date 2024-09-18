#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isOkay(int MAX, int money, vector<int>& pays) {
	for (int pay : pays) {
		if (pay <= MAX) {
			money -= pay;
		}
		else money -= MAX;
	}
	if (money >= 0) return true;
	else return false;
}

void algorithm(int n, vector<int>& pays, int money) {
	int MAX = pays[pays.size() - 1];
	int MIN = 1;
	while (true) {
		if (MAX == MIN || MAX == MIN + 1) break;
		if (!isOkay((MAX + MIN) / 2, money, pays))  {
			MAX = (MAX + MIN) / 2;
		}
		else {
			MIN = (MAX + MIN) / 2;
		}
	}
	if (isOkay(MIN + 1, money, pays)) cout << MIN + 1;
	else cout << MIN;
}
int main() {
	int n;
	cin >> n;

	vector<int> pays;
	for (int i = 0; i < n; i++) {
		int pay;
		cin >> pay;
		pays.push_back(pay);
	}
	sort(pays.begin(), pays.end());

	int money;
	cin >> money;
	algorithm(n, pays, money);
}
