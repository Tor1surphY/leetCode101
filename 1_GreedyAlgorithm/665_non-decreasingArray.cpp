/*
给你一个长度为 n 的整数数组
请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 
对于数组中所有的 i (0 <= i <= n-2)
总满足 nums[i] <= nums[i + 1]。
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

int main(){
    // greedy strategy:
    // keep every 3 nums non-decreasing
    // but their are 2 different situations:
    // 1. left < right
    //    make mid = left
    // 2. left > right
    //    make left = mid
    vector<int> nums = {4,2,3};
    if(nums.size() < 3){
        cout << "true" << endl;
        return 0;
    }
    nums.insert(nums.begin(), -100000);
    int cnt = 0;
    int left;
    for(int i = 1; i < nums.size()-1; ++i){
        if(nums[i] > nums[i+1]){
            ++cnt;
            // if second change needed, false
            if(cnt > 1){
                cout << "false" << endl;
                return 0;
            }
            left = nums[i-1];
            if(left > nums[i+1]) nums[i+1] = nums[i];
            else                 nums[i] = nums[i-1];
        }
    }
    cout << "true" << endl;
    return 0;
}