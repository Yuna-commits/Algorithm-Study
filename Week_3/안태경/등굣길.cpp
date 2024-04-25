#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    dp[1][0] = 1;
    for(vector<int> puddle : puddles){
        int x = puddle[0];
        int y = puddle[1];
        dp[x][y]= -1;
    }
    for(int i = 1; i < m+1; i++){
        for(int j = 1; j < n+1; j++){
            if (dp[i][j] == -1){
                dp[i][j]=0;
                continue;
            }
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= 1000000007;
        }
    }
    int answer = dp[m][n];
    return answer;
}
