#include <string>
#include <vector>
#include <cctype>

using namespace std;

//1단계
string upper_to_low(string new_id){
    string result= new_id;
    for(int i = 0; i<new_id.length(); i++){
        if(isupper(new_id[i]))
           result[i] = tolower(new_id[i]);
    }
    return result;       
}

//2단계
string remove_str(string new_id){
    string result = new_id;
    for(int i = 0; i<result.length(); i++){
        if(!isalpha(result[i]) && !isdigit(result[i]) &&
                result[i] != '-' && result[i] != '_' && result[i] != '.'){
            result.erase(i,1);
            i--;
        }
    }
    return result;
}

//3단계
string exchange_dot(string new_id){
    string result = new_id;
    for(int i = 0; i<result.length(); i++){
        if(result[i] == '.' && result[i+1] == '.') {
            result.erase(i,1);
            i--;
        }
    }
    return result;
}

//4단계
string remove_dot(string new_id){
    string result = new_id;
    if(result[0] == '.') result.erase(0,1);
    if(result[result.length()-1] == '.') result.erase(result.length()-1, 1);
    return result;
}

//5단계
string ifempty(string new_id){
    if(new_id == "") return "a";
    return new_id;
}

//6단계
string iftoolong(string new_id){
    string result = new_id;
    if(result.length() >= 16){
        for(int i = new_id.length(); i>15; i--)
            result.erase(i-1,1);
        if(result[14] == '.') result.erase(14,1);
    }
    return result;
}

//7단계
string iftooshort(string new_id){
    string result = new_id;
    int len = new_id.length();
    if(len <= 2) {
        result.append(3-len, result[len-1]);
    }
    return result;
} 

string solution(string new_id) {
    string answer = "";
    answer = upper_to_low(new_id);
    answer = remove_str(answer);
    answer = exchange_dot(answer);
    answer = remove_dot(answer);
    answer = ifempty(answer);
    answer = iftoolong(answer);
    answer = iftooshort(answer);
    return answer;
}