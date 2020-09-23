/*
给定一个只包含整数的有序数组，每个元素都会出现两次，
唯有一个数只会出现一次，找出这个数。
您的方案应该在O(logN)时间复杂度和O(1)空间复杂度中运行。
*/

#include "../head.h"

// 思路
// 如果所有元素都是两次，那么每个元素的下标都是[even, odd]
// 如果出现了只出现一次的元素，那么这个元素后面的所有元素都会变成[odd, even]
//     mid是奇数时和左边比，是偶数时和右边比
//     一旦不相等时，说明只出现一次的元素在mid左边
//     区间改为[start, mid]
//     反之，那么只出现一次的元素在mid右边
//     区间改为[mid, end]
// 注意：
// 为了保证每一个区间的相似性，在没出现目标情况时
// 要保证被除去的是成对的元素
// 
// * 目标元素的下标一定是偶数                        
// * 所以奇数的情况下要注意区间的选择
// * 二分查找的区间会一直剔除目标元素左右俩边的成对元素
// * 最终收敛于以目标元素为开头的区间                 
// * 一旦以目标元素为开头，就会不断剔除右边的元素      
// * 直至区间收敛为目标元素                          
int singleNonDuplicate(vector<int>& nums) {
    int l = 0, r = nums.size()-1;
    int mid;
    while(l < r){
        mid = (l+r)/2;
        // 不相等的情况下，有可能mid就是目标值
        // 所以要把mid包含在查找区间内
        // 如果不包含这个pair，有可能出现三个数连续不相等的情况
        if(mid%2 == 0){
            // 相等的情况下，包含这个数即可，防止访问越界问题
            if(nums[mid] == nums[mid+1]) l = mid;
            else                         r = mid;
        }
        else{
            // 相等的情况下，刨去这个pair
            if(nums[mid] == nums[mid-1]) l = mid+1;
            else                         r = mid;
        }
    }
    return nums[l];
}

int main(){
    vector<int> nums = {1,1,2,3,3,4,4};
    cout << singleNonDuplicate(nums) << endl;
    return 0;
}