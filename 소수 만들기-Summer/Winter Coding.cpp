#include <vector>
#include <cmath>
using namespace std;

int sosu(int sum){
    if(sum <= 2) return 1;
    int a = sqrt(sum);
    for(int i=2; i<=a; i++) if(sum%i==0) return 0;
    return 1;
}

int solution(vector<int> nums) {
    int answer = 0;
    int sum=0;
    for(int i=0; i<=nums.size()-3; i++){ //첫번째 수 
        for(int j=i+1; j<=nums.size()-2; j++){ //두번째 수 
            for(int m=j+1; m<=nums.size()-1; m++){//세번째 수 
                sum = nums[i]+nums[j]+nums[m];
                if(sosu(sum)==1) answer++;
            }
        }
    }
    return answer;
}