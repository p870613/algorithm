int divide(int dividend, int divisor) {
    if(divisor == INT_MIN && dividend == INT_MIN) return 1;
    if(dividend == INT_MIN && divisor == 1) return INT_MIN;
    if(divisor == INT_MIN) return 0;
    
    int flag = (dividend < 0 == divisor < 0);
    long long a = (dividend < 0)? -(long long)dividend:dividend;
    long long b = (divisor < 0)? -(long long)divisor:divisor;
    long long ret = 0;

    while (b <= a) {
        long long index = 0;
        while(a > (b<<(index+1)))
            index ++;
        ret = ret + (1 << index);
        a = a - (b << index);
    }

    if(flag == false)
        return -ret;
    if(ret == 2147483648)
        return ret-1;
    return ret;
}
