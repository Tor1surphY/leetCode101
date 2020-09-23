/*
给你两个有序整数数组 nums1 和 nums2
请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
*/
#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i) 

int main(){
    // 2 arrays are sorted
    // 2 pointers on the end of both arrays
    // bigger one set to the end of array1
    // which one is set --this pointer until the end
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;
    int insert_pos = m-- + n-- - 1;
    while(m >= 0 && n >= 0){
        if(nums1[m] < nums2[n]) nums1[insert_pos--] = nums2[n--];
        else nums1[insert_pos--] = nums1[m--];
    }
    while(n >= 0) nums1[insert_pos--] = nums2[n--];
    rep(i, nums1.size()) cout << nums1[i] << " ";
    cout << endl;
    return 0;
}