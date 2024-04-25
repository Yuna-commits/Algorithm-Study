#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(int scov : scoville)
        min_heap.push(scov);
    while(min_heap.top() < K){
        if(min_heap.size() < 2)
            return -1;
        int min_number = min_heap.top();
        min_heap.pop();
        int min2_number = min_heap.top();
        min_heap.pop();
        min_heap.push(min_number + min2_number*2);
        answer++;
    }
    return answer;
}
