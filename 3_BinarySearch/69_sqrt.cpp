/*
实现int sqrt(int x)函数。
计算并返回x的平方根，其中x是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
*/
#include "../head.h"

int main(){
    int x = 8;
    if(0 == x) return 0;
    int l = 1, r = x;
    int mid, sqr;
    while(l <= r){
        mid = (r+l)/2;
        sqr = x/mid;
        // because sqr = x/mid
        // when sqr == mid, sqr = x/sqr
        // means sqr*sqr == x, that's the answer
        if(sqr == mid)     return mid;
        // when sqr < mid
        // means real sqr on the left side
        else if(mid > sqr) r = mid-1;
        // else on the right side
        else               l = mid+1;
    }
    return r;
}