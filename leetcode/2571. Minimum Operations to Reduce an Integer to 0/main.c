int minOperations(int n){
    int ret = 0, cnt = 0;

    while(n > 0) {
        if(n & 1) {
            cnt ++;
        } else if(cnt) {
            ret = ret + 1;
            if(cnt > 1)
                cnt = 1;
            else 
                cnt = 0;
        }
        n = n >> 1;
    }
    if(cnt == 1)
        ret ++;
    else if(cnt > 1)
        ret = ret + 2;
    return ret;
}
