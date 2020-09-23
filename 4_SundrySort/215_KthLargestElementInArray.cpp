/*
在一个未排序的数组中，找到第K大的数字
（不使用sort/qsort函数）
*/
#include "../head.h"

void swap(vector<int>& nums, int a, int b){
    int c = nums[a];
    nums[a] = nums[b];
    nums[b] = c;
}

int findKthNumber(vector<int>& nums, int k, int l, int r){
    if(l >= r) return nums[l];
    int tag = l;
    int tmp;
    for(int i = l+1; i <= r; ++i){
        if(nums[i] > nums[tag]){
            tmp = i;
            break;
        }
    }
    for(int j = tmp+1; j <= r; ++j){
        if(nums[j] < nums[tag]){
            swap(nums, j, tmp);
            ++tmp;
        }
    }
    swap(nums, tag, tmp-1);
    tag = tmp-1;
    /***/
    if     (r-tag == k-1) return nums[tag];
    else if(r-tag <  k-1) return findKthNumber(nums, k-(r-tag)-1, l,     tag-1);
    else                  return findKthNumber(nums, k,           tag+1, r);
}

int main(){
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 0;
    cin >> k;
    int l = 0, r = nums.size()-1;
    cout << "The Kth number in array is: " 
         << findKthNumber(nums, k, l, r) << endl;
    return 0;
}

// 总结：
// 一般需要社稷到排序且不能使用sort/qsort函数时，都应该优先考虑快速排序算法
// 对于本题而言，仅仅需要找到第K大的数是不需要排序的
// 快速排序的本质是分治法，所以快速选择也是
// 要注意边界条件