#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b){
        return a[2] < b[2];
    });
    vector<bool> way(n,false);
    vector<int> choice;
    int i = 0;
    bool signal1 = true, signal2 = false;
    while(i < costs.size()){
        if(way[costs[i][0]] == false){
            way[costs[i][0]] = true;
            signal2 = true;
        }
        if (way[costs[i][1]] == false){
            way[costs[i][1]] = true;
            signal2 = true;
        }
        if(signal2==true)
            choice.push_back(i);
            for (bool sig : way){
                if (sig == false){
                    signal1 = false;
                    break;
                }
            }
        if(signal1 == true)
            while(choice.size() < n-1){
                for(int j = 0; j < costs.size(); j++){
                    for (int k : choice){
                        if (j == k){
                            continue;
                        }
                        else{
                            choice.push_back(j);
                            if(choice.size() == n-1)
                                break;
                        }
                    }
                    break;
                }
                break;
            }
        signal1 = true;
        signal2 = false;
        i++;
    }
    int answer = 0;
    for (int j : choice){
        answer += costs[j][2];
    }
    
    
    return answer;
}
