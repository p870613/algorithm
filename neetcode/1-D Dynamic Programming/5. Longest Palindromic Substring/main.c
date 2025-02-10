char* longestPalindrome(char* s) {
    char *ans = (char *)malloc(sizeof(char) * 1001);
    int index = 0;
    int len = 0;
    int l, r;

    memset(ans, '\0', 1001);
    for (int i = 0; i < strlen(s); i++) {
        l = i, r = i;
        while (l >= 0 && r < strlen(s) && s[l] == s[r]) {
            if (r - l + 1 > len) {
                index = i;
                len = r - l + 1;
            }
            r ++;
            l --;
        }

        l = i, r = i + 1;
        while (l >= 0 && r < strlen(s) && s[l] == s[r]) {
            if (r - l + 1 > len) {
                index = i;
                len = r - l + 1;
            }
            r ++;
            l --;
        }
    }

    int offset = (len % 2 == 0) ? len / 2 - 1 : len / 2;
    int start_index = index - offset;
 
    for (int i = 0; i < len; i++)
        ans[i] = s[start_index + i];

    return ans;
}
