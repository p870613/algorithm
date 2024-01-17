int lengthOfLastWord(char* s) {
    int ret = 0;

    for(int i = strlen(s)-1; i>=0; i--) {
        if(ret == 0 && s[i] == ' ')
            continue;
        else if(ret != 0 && s[i] == ' ')
            return ret;
        else
            ret ++;
    }   
    return ret;
}
