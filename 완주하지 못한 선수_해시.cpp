#include <string>
#include <vector>
#include <map>
using namespace std;


string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    
    for(auto p : participant){
        m[p] = 1;
    }
    
    for(auto c : completion){
        m[c] -= 1; 
    }
    
    for (auto p : participant){
        if(m[p] == 1 ) return p;
    }
}