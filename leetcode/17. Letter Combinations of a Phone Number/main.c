/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ar[8][5] = {"abc", "def", "ghi", "jkl", "mno", 
                  "pqrs", "tuv", "wxyz"};
int dig[8];

void dfs(char** ret, int cur_depth, int depth, int *index, char* letter) {
  /*to ret*/
  if(cur_depth >= depth) {    
    memcpy(ret[(*index)], letter, cur_depth);
    ret[(*index)][cur_depth] = 0;
    (*index)++;
    return;
  }
    
  int d = dig[cur_depth];
  
  for(int i = 0; i < strlen(ar[d]); i++) {
    letter[cur_depth] = ar[d][i];
    dfs(ret, cur_depth+1, depth, index, letter);
  }
 
}
char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    if(strlen(digits) == 0) {
      return NULL;
    }
    char **ret = (char**)malloc(sizeof(char*) * 256);
    for(int i = 0; i < 256; i++)
        ret[i] = (char*) malloc(sizeof(char) * 10);
    
    for(int i = 0; i < strlen(digits); i++) {
      dig[i] = digits[i] - '0' - 2;
    }

    char letter[10] = "";
    *returnSize = 0;
    dfs(ret, 0, strlen(digits), returnSize, letter);
    return ret;     
}
