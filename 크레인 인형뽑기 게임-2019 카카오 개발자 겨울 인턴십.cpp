#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> bucket;
    vector<vector<int>> b = board;
    
    for(int i : moves){
        int j = 0; 
        for(int j = 0; j < b.size(); j++){
            if(b[j][i-1] != 0){
                bucket.push_back(b[j][i-1]);
                if((bucket.size() > 1) && (bucket[bucket.size()-1] == bucket[bucket.size()-2])){
                    bucket.pop_back();
                    bucket.pop_back();
                    answer += 2;
                }
                b[j][i-1] = 0;
                break;
            }
        }
    }
    
    return answer;
}