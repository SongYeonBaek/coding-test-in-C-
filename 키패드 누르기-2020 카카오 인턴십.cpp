#include <string>
#include <vector>

using namespace std;

int distance (int n, int e ){
    int a = n; int b = e;
    if(a == 0) a = 11; 
    if(b == 0) b = 11; 
    
    int gap = abs(a-b);
    if(gap == 0) return 0;
    else if(gap ==1 || gap == 3) return 1; 
    else if(gap ==2 || gap == 4 || gap == 6) return 2;
    else if(gap ==5 || gap ==7 || gap == 9) return 3;
    else if(gap == 8 || gap == 10) return 4; 
    else return 100;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int l = 10; int r = 12;
    for(int i = 0; i < numbers.size(); i++) {
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer.append(1,'L');
            l = numbers[i]; 
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer.append(1,'R');
            r = numbers[i];
        }
        else {
            if(distance(numbers[i], l) == distance(numbers[i], r)) {
                if(hand == "left") {
                    answer.append(1, 'L'); 
                    l = numbers[i]; 
                }
                else {
                    answer.append(1,'R');
                    r = numbers[i];
                }
            }
            else if(distance(numbers[i], l) > distance(numbers[i], r) ){
                answer.append(1,'R');
                r = numbers[i];
            }
            else {
                answer.append(1, 'L'); 
                l = numbers[i]; 
            }
        }
    }
    return answer;
}