/*
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c。
*/
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

// two pointer:
// same as 167

// consider about the O(N)
// when c > 200,000 we cannot get result on time
// because c >= 0, so ceil(sqrt(c))^2 >= c
// we already set a = 0, so O(N) reduce 200,000 to 500

class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        double a = 0, b = ceil(sqrt(c)), ans;
        while(a < c && b > 0){
            ans = a*a + b*b;
            if(ans > c) --b;
            else if(ans < c) ++a;
            else return true;
        }
        return false;
    }
};

int main(){
    Solution test;
    cout << test.judgeSquareSum(999999) << endl;
    return 0;
}