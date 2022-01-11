#include <iostream>
using namespace std;

void print(int* ar, int len) {
    for(int i = 0; i < len; i++)
        cout << ar[i] << " ";
    cout << endl;
}

void merge(int* ar, int l, int m, int r) {
    int L [m - l +  1], R [r - m];
    
    for(int i = 0; i < (m - l + 1); i++)
        L[i] = ar[l + i];
    for(int i = 0; i < (r - m); i++)
        R[i] = ar[m + 1 + i];

    int L_index = 0, R_index = 0, ar_index = l;
    while (L_index < (m - l + 1) && R_index < (r - m)) {
        if(L[L_index] < R[R_index]) 
            ar[ar_index ++ ] = L[L_index ++]; 
        else if(L[L_index] > R[R_index]) 
            ar[ar_index ++ ] = R[R_index ++];
    }

    if(L_index < (m - l + 1)) {
        while(L_index < (m - l + 1))
            ar[ar_index ++ ] = L[L_index ++];
    }

    if(R_index < (r - m)) {
        while(R_index < (r - m))
            ar[ar_index ++ ] = R[R_index ++];
    }
}
void merge_sort(int* ar, int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        merge_sort(ar, l, m);
        merge_sort(ar, m + 1, r);
        merge(ar, l, m, r);
    }
}

int main() {
    int ar[] = {1, 5, 20, 4, 10};
    int len = sizeof(ar) / sizeof(int);
    print(ar, len);
    merge_sort(ar, 0, len - 1);
    print(ar, len);
}
