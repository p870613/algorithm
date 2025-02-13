int check(char a, char b) {
    if (((a - '0') * 10 + b - '0') <= 26)
        return true;
    return false;
}

int numDecodings(char* s) {
    int dp[101] = {0};

    dp[strlen(s)] = 1;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == '0') {
            dp[i] = 0;
        } else {
            dp[i] = dp[i+1];
            if (i + 1< strlen(s) && check(s[i], s[i+1]))
                dp[i] = dp[i+1] + dp[i+2];
        }
    }
    return dp[0];

}
