#include <iostream>

using namespace std;

int x, y;
int f(int a, int b){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }else{
        int ans = f(b, a%b);    
        int tmp = y;
        y = x - a / b * y;
        x = tmp;
        return ans;
    }
}

int main(){
    int n, m;
    while(cin >> n >> m){
        cout <<  f(n, m) << endl;
        cout << x << " " << y << endl;
    }
}
