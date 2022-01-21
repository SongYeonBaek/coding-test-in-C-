#include <string>
#include <vector>
using namespace std;

int findname(string name, vector<string> id_list){
   for(int i = 0; i < id_list.size(); i++){
       if(id_list[i] == name) return i;
   }
    return 100;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    vector < vector<string>> list(id_list.size(), vector<string>(0));
    string a, b;
    
    for(string s : report){
        a = s.substr(0, s.find(" "));
        b = s.substr(s.find(" ")+1, s.length()-s.find(" ")-1);
        int f=0;
        for(string l : list[findname(b,id_list)])
            if(l == a) f=1;
        if(f==0) list[findname(b, id_list)].push_back(a);
    }
    
    for (int i = 0; i <list.size(); i++){
        if(list[i].size() >= k) {
            for(string n : list[i]){
                answer[findname(n, id_list)] += 1; 
            }
        }
    }
    
    return answer;
}