/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
(例如，数组[0,0,1,2,2,5,6]可能变为[2,5,6,0,0,1,2])。
编写一个函数来判断给定的目标值是否存在于数组中。
若存在返回true，否则返回false。
*/

#include "../head.h"

// 思路：
// 旋转数组可以看作是两个递增数组的反向拼接
// 寻找目标值的关键就在于找到连续的区间
// 所以，if(mid < end)，那么说明[mid, end]是连续的
//           if(mid <= target <= end)  start = mid;
//           else                      end   = mid-1;
//       else，那么说明[start, mid]是连续的
//           if(start <= target < end) end   = mid-1;
//           else                      start = mid+1
// 如果刚好mid == start，那么无法判断那边是连续递增区间
// 这个时候++start，再重新进行查找，直到符合前面的条件为止
// 特殊情况：
//     所有元素相等，这样strat递增至end退出循环，返回false
//     解决，if(nums[mid] == target) return true;

bool search(vector<int>& nums, int& target){
    int start = 0, end = nums.size()-1;
    int mid;
    while(start <= end){
        mid = (start+end)/2;
        if(target == nums[mid]) return true;
        if     (nums[start] == nums[mid])                   ++start;
        else if(nums[mid] <= nums[end]){
            if(target > nums[mid] && target <= nums[end])   start = mid+1;
            else                                            end   = mid-1;
        }
        else{
            if(target >= nums[start] && target < nums[mid]) end   = mid-1;
            else                                            start = mid+1;
        }
    }
    return false;
}

int main(){
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 3;
    cout << search(nums, target) << endl;
    return 0;
}