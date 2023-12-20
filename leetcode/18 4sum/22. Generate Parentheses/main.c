
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int ret_index;
char **ret;
void solve(int open, int close, char* output, int n)
{
    if(open == 0 && close == 0) {     
        output[n] = 0;
        strncpy(ret[ret_index], output, n+1);
        ret_index ++;
        return;
    }
    if(open > 0) {
        output[n] = '(';
        solve(open-1, close, output,n+1);
        output[n] = ' ';
    }

    if(close > open) {
        output[n] = ')';
        solve(open, close-1, output,n+1);
        output[n] = ' ';
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int open = n;
    int close = n;
    int len = pow(2, 2*n);
    char *output = (char*)malloc(n*2+2);
    ret_index = 0;
    ret = (char**) malloc(sizeof(char*) * len);
    for(int i = 0; i < len; i++)
        ret[i] = (char*)malloc(sizeof(char) * n * 2 + 2);
    solve(open, close, output, 0);
    free(output);
    *returnSize = ret_index;
    return ret;   
}
