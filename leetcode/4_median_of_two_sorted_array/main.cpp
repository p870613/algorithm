#include <iostream>
#include <vector>
int findelement(int, std::vector<int>&, std::vector<int>& , int, int);
void input(std::vector<int> *ar){
    int n;
    std::cin >> n;  
    for(int i = 0; i < n; i++){
        int in;
        std::cin >> in;
        ar->push_back(in);
    }
    
}

double findMedianSortedArrays(std::vector<int>& num1, std::vector<int>& num2) {
    int m = num1.size();
    int n = num2.size();
    int left = (m + n + 1) / 2, right = (m + n + 2) / 2;
    return (findelement(left, num1, num2, 0, 0) + findelement(right, num1, num2, 0, 0)) / 2.0;
}

int min(int a, int b){
    if(a > b) return b;
    return a;
}
int findelement(int k, std::vector<int>& num1, std::vector<int>& num2, int num1_cur, int num2_cur){// 
    if(num1_cur >= num1.size()) return num2[num2_cur + k - 1];
    if(num2_cur >= num2.size()) return num1[num1_cur + k - 1];
    if(k == 1) return min(num1[num1_cur], num2[num2_cur]);

    int num1_mid = (num1_cur + k / 2 - 1 < num1.size()) ? num1[num1_cur + k / 2 - 1] : 1e9;
    int num2_mid = (num2_cur + k / 2 - 1 < num2.size()) ? num2[num2_cur + k / 2 - 1] : 1e9;
    if(num1_mid > num2_mid)
        return findelement(k - k / 2, num1, num2, num1_cur, num2_cur + k / 2);
    else
        return findelement(k - k / 2, num1, num2, num1_cur + k / 2, num2_cur);
    
}


int main(){
    std::vector <int> num1, num2;
    input(&num1);
    input(&num2);

    std::cout << findMedianSortedArrays(num1, num2);
}



