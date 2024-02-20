void reverse(char *str, int len) {
    for(int i = 0; i < len/2; i++) {
        char t = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = t;
    }
}
char* addBinary(char* a, char* b) {
     int i = strlen(a) - 1;
     int j = strlen(b) - 1;
     int carry = 0, index = 0;
     char *ret = (char*)malloc(sizeof(char) * 10005);

    while(i >= 0 || j >= 0 || carry) {
        if(i >= 0)
            carry = carry + a[i--] - '0';
        if(j >= 0)
            carry = carry + b[j--] - '0';
        ret[index++] = carry % 2 + '0';
        carry = carry / 2;
    }
    ret[index] = '\0';
    reverse(ret, index);
    // printf("%s\n", ret);
    return ret;
}
