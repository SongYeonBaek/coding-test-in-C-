#include <string>
#include <vector>

using namespace std;

int ifcomplete(string buf){
   if(buf == "zero") return 0;
   else if(buf == "one") return 1; 
   else if(buf == "two") return 2;
   else if(buf == "three") return 3;
   else if(buf == "four") return 4;
   else if(buf == "five") return 5;
   else if(buf == "six") return 6;
   else if(buf == "seven") return 7;
   else if(buf == "eight") return 8;
   else if(buf == "nine") return 9;
   else return -1;
}

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.length(); i++){
        //숫자인 경우
        if(isdigit(s[i])) { 
            answer = (answer + s[i] - 48) * 10; 
        }
        
        //문자열인 경우
        else { 
            string buf = "";
            while(!isdigit(s[i])){
                char c = s[i];
                buf.append(1, c);
                if(ifcomplete(buf)>=0) break;
                i++;
            }
            answer = (answer + ifcomplete(buf)) * 10; 
        }
    }
    return answer/10;
}