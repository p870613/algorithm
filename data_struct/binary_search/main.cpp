#include <stdio.h>

int binary_search(int* ar, int len, int n) {
    int l = 0, r = len;
    while(l < r) {
        int m = (l + r) / 2;
        if(ar[m] < n) {
            l = m + 1;
        } else if( ar[m] > n){
            r = m;
        }else{
            return m;
        }
    }
    return -1;
}
int main() {
    int ar[5] = {1, 2, 3, 4, 5};
    printf("%d\n", binary_search(ar, 5, 1));
    printf("%d\n", binary_search(ar, 5, 2));
    printf("%d\n", binary_search(ar, 5, 3));
    printf("%d\n", binary_search(ar, 5, 4));
    printf("%d\n", binary_search(ar, 5, 5));
}
