/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
(例如，数组[0,1,2,4,5,6,7]可能变为[4,5,6,7,0,1,2])。
请找出其中最小的元素。
注意数组中可能存在重复的元素。
*/

#include "../head.h"

// 思路：
// 两个连续递增的数组
// 第一个数组的最小值就是nums[0]
// 只需要找到第二个数组的最小值，也就是要找到中点
// 其他思路与No.34相同
// 此算法区间收敛于第二个递增区间的首元素
int findMin(vector<int>& nums) {
    int start = 0, end = nums.size()-1;
    int mid;
    while(start < end){
        // 区间递增，返回start是最小值
        if(nums[start] < nums[end]) return nums[start];
        
        mid = (start+end)/2;
        // mid == end，不能确定是否递增，就++strat
        if     (nums[mid] == nums[end]) ++start;
        // mid以右递增, 区间左移（递增的部分直接舍弃）
        else if(nums[mid] <  nums[end]) end = mid;
        // mid以左递增，区间右移（左边区间不需要）
        else                            start = mid+1;
    }
    return nums[start];
}

int main(){
    vector<int> nums = {3,3,1,3};
    cout << findMin(nums) << endl;
    return 0;
}