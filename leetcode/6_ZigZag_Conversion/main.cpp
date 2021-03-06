#include <iostream>
#include <string>
#include <vector>

std::string convert(std::string s,const int n) {
    if(n == 1)
        return s;
        
    std::string ans[n];
    for(int i = 0; i < n; i++)
        ans[i] = "";

    for(int i = 0; i < s.size(); i++){
        int pos = (i % (2 * n - 2));
        if(pos >= n){
            pos = 2 * (n - 1) - pos;
        }
        ans[pos] = ans[pos] + s[i];
    }

    std::string ret = "";
    for(int i = 0; i < n; i++){
        ret = ret + ans[i];
        ans[i].clear();
    }

    return ret;
}
int main(){
    std::string input;
    int n;
    std::cin >> input >> n;
    std::cout << convert(input, n);    
}
