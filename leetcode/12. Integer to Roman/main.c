char* intToRoman(int num) {
    int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbol[] = {"M", "CM", "D", "CD","C", "XC","L", "XL","X","IX", "V", "IV","I"};
    char* ret = (char*)malloc(100);
    int index = 0;

    memset(ret, 0, 100);
    for(int i = 0; i < 13; i++) {
        int count = num / value[i];
        num = num - value[i] * count;
        for(int j = 0; j < count; j++) {
            strcpy(ret+index, symbol[i]);
            index = index + strlen(symbol[i]);
        }
    }
    return ret;   
}
