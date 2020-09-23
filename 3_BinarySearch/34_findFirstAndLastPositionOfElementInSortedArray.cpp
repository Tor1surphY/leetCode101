/*
给定一个按照升序排列的整数数组nums，和一个目标值target。
找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是O(logN)级别。
如果数组中不存在目标值，返回[-1, -1]。
*/
#include "../head.h"

// find the first target if exists
int findLowerPos(const vector<int>& nums, const int& target){
    int l = 0, r = nums.size(), mid;
    while(l < r){
        mid = (l+r)/2;
        // if mid is bigger or equal to target
        // means lower on left side
        // once ture, erase some target num
        if(nums[mid] >= target) r = mid;
        // if less than target
        // means lower on right side
        // make l reach to r
        else                    l = mid+1;
    }
    return l;
}


// find the first one that bigger than target
int findUpperPos(const vector<int>& nums, const int& target){
    int l = 0, r = nums.size(), mid;
    while(l < r){
        mid = (l+r)/2;
        if(nums[mid] > target) r = mid;
        else                    l = mid+1;
    }
    return l;
}


int main(){
    vector<int> nums = {2, 2};
    int target = 3;
    // 目的：
    // 寻找第一个target和第一个不是target的数
    // 总结:
    // 不设返回的二分查找最终会收敛于判断条件下r的数值

    vector<int> ans = {-1, -1};
    int lower_pos = findLowerPos(nums, target);
    int upper_pos = findUpperPos(nums, target);
    if(lower_pos >= nums.size() 
       || nums.size() == 0 
       || nums[lower_pos] != target){
        cout << ans[0] << " " << ans[1] << endl;
        return 0;
    }
    ans[0] = lower_pos;
    ans[1] = upper_pos-1;
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}