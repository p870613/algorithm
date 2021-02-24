#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<int, int>map;
    int ret = 0, left = -1;
    for(int i = 0; i < s.size(); i ++){
        if(map.count(s[i]) && map[s[i]] > left){
            left = map[s[i]];
        }
        map[s[i]] = i;
        ret = max(ret, i - left);
    }
    return ret;
}
int main(){
    std::string input;
    std::cin >> input;
    std::cout << lengthOfLongestSubstring(input);
}
