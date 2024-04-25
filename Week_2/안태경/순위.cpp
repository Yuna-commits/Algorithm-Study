#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> tier(n,vector<int>(2));
    
    for (int i = 0; i < n; i++){
        tier[i][0]=1;
        tier[i][1]=n;
    }
    
    for (vector<int> play : results){
        int win = play[0]-1;
        int lose = play[1]-1;
        tier[win][1] = min(tier[win][1],tier[lose][1]) - 1;
        tier[lose][0] = max(tier[win][0],tier[lose][0]) + 1;
    }
    for (vector<int> play : results){
        int win = play[0]-1;
        int lose = play[1]-1;
        if (tier[win][1] >= tier[lose][1])
            tier[win][1] = min(tier[win][1],tier[lose][1]) - 1;
        if(tier[lose][0] <= tier[win][0])
            tier[lose][0] = max(tier[win][0],tier[lose][0]) + 1;
    }
    
    vector<int> signal(n,1);
    for (int i = 0; i < n; i++) {
        signal[tier[i][0]-1]=signal[tier[i][0]-1] + 1;
        signal[tier[i][1]-1]=signal[tier[i][1]-1] + 1;
    }
    for (int i = 0; i < n; i++) {
        if (signal[i] == 1) {
            answer++;
        }
    }
    for (int i = 0; i <n; i++){
        if (tier[i][0]==tier[i][1]) answer++;
    }
    return answer;
}
