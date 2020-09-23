/*
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
*/
#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i) 

int main(){
    // array is sorted
    // double pointer:
    // one from left to right, the other from right to left
    // there do have an answer in this case
    // when sum less than target, ++left pointer
    // when sum more than target, --right pointer
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    int i = 0, j = numbers.size()-1;
    while(1){
        if     (numbers[i] + numbers[j] == target) break;
        else if(numbers[i] + numbers[j] <  target) ++i;
        else if(numbers[i] + numbers[j] >  target) --j;
    }
    vector<int> ans(2);
    ans[0] = ++i;
    ans[1] = ++j;
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}