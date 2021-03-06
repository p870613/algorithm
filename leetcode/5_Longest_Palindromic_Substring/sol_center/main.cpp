#include <iostream>
#include <string>

int center(std::string s, int left, int right){
    while(left >= 0 && right < s.size()){
        if(s[left] == s[right]){
            left --;
            right ++;
        }else{
            return right - left - 1;
        }
    }
    return right - left - 1;

}

std::string longestPalindrome(std::string s) {
    if(s.size() < 1)
        return "";

    int index = 0, max_len = 1;
    for(int i = 0; i < s.size(); i++){
        int odd = center(s, i, i);
        int even = center(s, i, i+1);
        int len = (odd > even) ? odd : even;
        if(max_len < len){
            max_len = len;
            index = i - (len - 1) / 2;
        }
    }
    return s.substr(index, max_len);
}

int main(){
    std::string input;
    std::cin >> input;
    std::cout << longestPalindrome(input) << std::endl;; 
}
