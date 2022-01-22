#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    vector<int> leftover;
    for(int i=0; i<=9; i++){
        leftover.push_back(i);
    }
    
    for(int i : numbers){
        leftover[i] = 0;
    }
   
    for(int i = 0; i<leftover.size(); i++){
        cout <<  leftover[i] << " " ;
        answer += leftover[i];
    }
    return answer+1;
}