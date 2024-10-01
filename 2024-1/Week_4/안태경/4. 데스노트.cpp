#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int people, width;
vector<int> name;
int deathnote(int index, int result, int remain) {
	if (index == people) {
		return result;
	}
	if (remain - (name[index] + 1) >= 0) {
		return min(deathnote(index + 1, result, remain - (name[index] + 1)), deathnote(index + 1, result + remain * remain, width - name[index]));
	}
	else {
		return deathnote(index + 1, result + remain * remain, width - name[index]);
	}
}

int main() {
	cin >> people >> width;
	name.resize(people);
	for (int i = 0; i < people; i++) {
		cin >> name[i];
	}
	int result = deathnote(1, 0, width - name[0]);
	cout << result;
}
