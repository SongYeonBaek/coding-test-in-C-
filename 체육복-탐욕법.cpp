#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int>::iterator it;
    for(int i=0; i<lost.size(); i++){
        int num = lost[i];
        it = find(reserve.begin(), reserve.end(), num);
        if(it != reserve.end()){
            reserve.erase(it);
            lost[i] = 0; 
            answer++;
        }
    }
    
    for(int i=0; i<lost.size(); i++){
        if(lost[i] == 0) continue;
        for(int j=0; j<reserve.size(); j++){
            if(lost[i]-1 == reserve[j]){ 
                cout<< "lost[" << i << "] = " << lost[i] << "를 삭제함 ";
                lost[i] = 0;
                cout<<"reserve[" << j << "] = " << reserve[j] << "를 삭제함\n";
                reserve[j] = -1;
                answer++;
                break;
            }
        }
        for(int j=0; j<reserve.size(); j++){
            if(lost[i]+1 == reserve[j]){ 
                cout<< "lost[" << i << "] = " << lost[i] << "를 삭제함 ";
                lost[i] = 0;
                cout<<"reserve[" << j << "] = " << reserve[j] << "를 삭제함\n";
                reserve[j] = -1;
                answer++;
                break;
            }
        }
    }
    cout<< "\n\n";
    for(int i=0; i<lost.size(); i++){
        cout << lost[i] << " ";
    }
    cout<<"\n";
    for(int i=0; i<reserve.size(); i++){
        cout << reserve[i] << " ";
    }
    
    return n - (lost.size() - answer);
}