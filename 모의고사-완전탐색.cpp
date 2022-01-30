#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int find_index(vector<int> a, int c){
    for(int i=0; i<a.size(); i++){
        if(a[i] == c ) return i;
    }
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> hit(3);
    vector<int> su1 = {1, 2, 3, 4, 5}; 
    vector<int> su2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> su3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i=0; i<answers.size(); i++){
        if(su1[i % su1.size()] == answers[i]) hit[0]++; 
        if(su2[i % su1.size()] == answers[i]) hit[1]++;
        if(su3[i % su1.size()] == answers[i]) hit[2]++;
    }
    
    vector<int> copy = hit;
    sort(copy.begin(), copy.end());
    
    for(int i=2; i>=0; i--){
        answer.push_back(find_index(hit, copy[i])+1);
        hit[ find_index(hit, copy[i]) ] = -1;
        if(copy[i] != copy[i-1]) break; 
    }
    
    return answer;
}