#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = A.size();
    sort(B.begin(), B.end());
    sort(A.begin(), A.end());
    vector<int> match;
    int count = 0, a = 0;
    for(int b : B){
        for(a; a < answer; a++){
            if (b > A[a]) count++;
            else {
                break;
            }
        }
        match.push_back(count);
    }
    int rank = 0;
    for(int i = 0; i < match.size(); i++){
        if(match[i] > i-rank) continue;
        else {
            answer--;
            rank++;
        }
    }
    return answer;
}
