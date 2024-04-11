#include <string>
#include <vector>

using namespace std;
int amount(vector<vector<int>> land,int a, int b){
    int result = 0;
    if (land[a+1][b] == 1){
        land[a][b] += amount(land,a+1,b);
    }
    if (land[a][b+1] == 1){
        land[a][b] += amount(land,a,b+1);
    }
    if (a-1 >= 0 && land[a-1][b] == 1){
        land[a][b] += amount(land,a-1,b);
    } 
    if (b-1 >= 0 && land[a][b-1] == 1){
        land[a][b] += amount(land,a,b-1);
    }
    return result;
}
int solution(vector<vector<int>> land) {
    int answer = 0;
    for (int j = 0; j<land.size();j++){
        for (int i = 0; i<land[j].size()-1;i++){
            if(land[j][i] == 0 && land[j][i+1]==1){
                answer += amount(land,j,i);
            }
        }
    }
    return answer;
}
