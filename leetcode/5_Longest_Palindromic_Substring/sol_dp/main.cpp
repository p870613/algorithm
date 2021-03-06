#include <iostream>
#include <string>

bool check(bool **dp, int i, int j, int len){
    if(i == j)
        return true;
    
    while(i < j){
            if(dp[i][j] == 1){
                i ++;
                j --;
            }else{
                return false;
            }
    }
    return true;
}

void print(bool **dp, int len){
    for(int i = 0; i < len; i ++){
        for(int j = 0; j < len; j++){
            std::cout << dp[i][j] << " "; 
        }
        std::cout << std::endl;
    }
    std::cout << "==========" << std::endl;
}

std::string longestPalindrome(std::string s) {
    if(s.size() < 1)
        return "";

    const int len = s.size();
    bool **dp = new bool*[len];
    for(int i = 0; i < len; i++){ 
        dp[i] = new bool[len];
        for(int j = 0; j < len; j++)
            dp[i][j] = 0;
    }
   
    int start = 0, ans_len = 0; 
    for(int i = 0; i < len; i++){
        for(int index = 0; index < len && (index+i) < len; index ++){
            if(s[index] == s[index+i] && check(dp, index+1, index+i-1, len)){
                dp[index][index+i] = 1;
                start = index;
                ans_len = i;
                std::cout << start << " " << ans_len << std::endl;
            }
        }
       //std::cout << i << std::endl;
    }

    print(dp, len);
    return s.substr(start, ans_len+1);
}

int main(){
    std::string input;
    std::cin >> input;
    std::cout << longestPalindrome(input) << std::endl;; 
}
