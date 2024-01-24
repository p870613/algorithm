void reverse(char *str) {
    for(int i = 0, j = strlen(str)-1; i < strlen(str)/2; i++,j--) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

void mul(char *num1, char *num2, char *ret) {
    int flag = 0;

    for(int i = 0; i < strlen(num1); i++) {
        for(int j = 0; j < strlen(num2); j++) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int pos = i + j;
            int sum = mul + ret[pos];

            ret[pos+1] = ret[pos+1] + sum / 10;
            ret[pos] = sum % 10;
        }
    }

    
    for(int i = strlen(num1) + strlen(num2) - 1; i >= 0 ; i--) {
        if(ret[i] == 0 && flag == 0)
            continue;
        flag = 1;
        ret[i] = ret[i] + '0';
    }
    if(flag == 0) {
        ret[0] = '0';
    }
    reverse(ret);
}

char* multiply(char* num1, char* num2) {
    char *ret = (char*)calloc(500, sizeof(char));

    reverse(num1);
    reverse(num2);

    mul(num1, num2, ret);
    return ret;
}
