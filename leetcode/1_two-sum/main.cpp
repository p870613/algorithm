#include <unordered_map>
#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& ar, int target) {
    std::unordered_map<int, int> map;
    for(int i = 0; i < ar.size(); i++){
        int find_element = target - ar[i];
        if(map.count(find_element)){
            return {map[find_element], i};
        }
        map[ar[i]] = i;
    }
    return {};
}

void print(std::vector<int>ar){
    for(int i = 0; i < ar.size(); i++)
        std::cout << ar[i] << " ";
    std::cout << std::endl;
}
int main(){
    int n, target;
    std:: cin >> n;
    std::vector<int> ar;
    for(int i = 0; i < n; i++){
        int input;
        std::cin >> input;
        ar.push_back(input);
    }
    std::cin >> target;
    std::vector<int>ans = twoSum(ar, target); 
    print(ans);
}
