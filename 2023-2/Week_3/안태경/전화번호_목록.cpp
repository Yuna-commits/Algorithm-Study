#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(),[](const string& a, const string& b){
        return a.size() < b.size();
    });
    
    unordered_set<string> hash;
    int size = 0;
    for(string& number : phone_book){
        string prefix = "";
        for(int j = 0; j < size; j++){
            prefix.push_back(number[j]);
            if(hash.count(prefix) > 0){
                return false;
            }
        }
        hash.insert(number);
        size = number.size();
    }
    
    
    return true;
}
