#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

bool is_prime(int num) {
	if (num < 2) return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

vector<int> prime = { 1, 3, 7, 9 };
void find_prime(int num, int len, int N) {
	if (len == N) {
		cout << num << '\n';
		return;
	}

	for (int temp : prime) {
		int new_num = num * 10 + temp;
		if (is_prime(new_num)) {
			find_prime(new_num, len + 1, N);
		}
	}
}

int main() {
	int N;
	cin >> N;
	vector<int> start = { 2, 3, 5, 7 };

	for (int num : start) {
		find_prime(num, 1, N);
	}
}
