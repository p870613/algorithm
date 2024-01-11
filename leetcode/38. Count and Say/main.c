char* countAndSay(int n) {
    char *ret = (char*)malloc(10000);
    char tmp[10000] = "11";

    if(n == 1) {
        ret[0] = '1';
        ret[1] = '\0';
        return ret;
    } else if(n == 2) {
        ret[0] = '1';
        ret[1] = '1';
        ret[2] = '\0';
        return ret;
    }

    for(int i = 2; i < n; i++) {
        int index = 0;
        for(int j = 0; j < strlen(tmp); j++) {
            int count = 1;
            while(j < strlen(tmp) && tmp[j] == tmp[j+1]) {
                count ++;
                j++;
            }
            ret[index++] = count + '0';
            ret[index++] = tmp[j];
        }
        ret[index] = '\0';
        strncpy(tmp, ret, index);
        index = 0;
    }
    return ret;
}
