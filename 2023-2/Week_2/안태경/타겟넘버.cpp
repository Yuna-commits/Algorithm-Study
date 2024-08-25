#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>& numbers, int target, int index, int sum, int& answer){
    if(index == numbers.size()){
        if(sum == target){
            answer++;
        }
        return;
    }
    
    dfs(numbers, target, index+1, sum + numbers[index], answer);
    dfs(numbers, target, index+1, sum - numbers[index], answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, 0, answer);
    return answer;
}
