int countSubstrings(char* s) {
    int ret = strlen(s);
    int len = strlen(s);
    int l, r;

    for (int i = 0; i < len; i++) {
        l = i, r = i + 2;
        while (l >= 0 && r < strlen(s) && s[l] == s[r]) {
            l --;
            r ++;
            ret ++;
        }

        l = i, r = i + 1;
        while (l >= 0 && r < strlen(s) && s[l] == s[r]) {
            l --;
            r ++;
            ret ++;
        }
    } 
    return ret;
}
