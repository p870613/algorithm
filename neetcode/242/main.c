bool isAnagram(char* s, char* t) {
    int sum[26];

    if(strlen(s) != strlen(t))
        return false;

    memset(sum, 0, sizeof(sum));

    for(int i = 0; i < strlen(s); i++) {
        sum[s[i] - 'a'] ++;
        sum[t[i] - 'a'] --;
    }

    for(int i = 0; i < 26; i++)
        if(sum[i] != 0)
            return false;
    return true;
}
