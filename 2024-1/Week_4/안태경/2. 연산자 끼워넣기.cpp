#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int N, add, sub, mul, divi, MAX = -1000000009, MIN = 1000000009;
vector<int> num;

void bfs(int count, int result, int add, int sub, int mul, int divi) {
	if (count == N) {
		MAX = max(result, MAX);
		MIN = min(result, MIN);
	}
	if (add > 0) {
		bfs(count + 1, result + num[count], add - 1, sub, mul, divi);
	}
	if (sub > 0) {
		bfs(count + 1, result - num[count], add, sub - 1, mul, divi);
	}
	if (mul > 0) {
		bfs(count + 1, result * num[count], add, sub, mul - 1, divi);
	}
	if (divi > 0) {
		if (result > 0) bfs(count + 1, result / num[count], add, sub, mul, divi - 1);
		else bfs(count + 1, -(-(result) / num[count]), add, sub, mul, divi - 1);
	}
}

int main() {
	cin >> N;
	num.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	cin >> add >> sub >> mul >> divi;

	bfs(1, num[0], add, sub, mul, divi);

	cout << MAX << '\n' << MIN;
}
