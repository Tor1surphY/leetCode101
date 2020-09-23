/*
给定一个包含红色、白色和蓝色，一共 n 个元素的数组
原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
0   1     2
red white blue
注意:
不能使用代码库中的排序函数来解决这道题。
*/

#include "../head.h"

void sortColors(vector<int>& nums) {
    vector<int> cnt(3, 0);
    for(auto& elem : nums) ++cnt[elem];
    int j = 0, tmp = 0;
    for(auto& elem : cnt) {
        for(int i = 0; i < elem; ++i) nums[j++] = tmp;
        ++tmp;
    }
}

/*
你能想出一个仅使用常数空间的一趟扫描算法吗？

原型：
    荷兰国旗问题，狄克斯特拉提出（又是你）
一次遍历，空间O(1)的解法：
    设置0的最右边界和2的最左边界
    遍历
        如果当前元素为0，则和0的最右边界交换，同时右移边界；
        如果当前元素为2，则和2的最左边界交换，同时左移边界；
        如果当前元素为1，则直接右移当前迭代器
     
*/
void sortColors(vector<int>& nums, bool re){
    // 对于所有 idx < p0 : nums[idx < p0] = 0
    // curr 是当前考虑元素的下标
    int p0 = 0, curr = 0, p2 = nums.size() - 1;
    while (curr <= p2) {
        if      (nums[curr] == 0) swap(nums[curr++], nums[p0++]);
        else if (nums[curr] == 2) swap(nums[curr],   nums[p2--]);
        else                      curr++;
    }
}

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    vector<int> nums_re = nums;
    sortColors(nums);
    for(auto& elem : nums) cout << elem << " ";
    cout << endl << endl;
    sortColors(nums_re, 1);
    for(auto& elem : nums_re) cout << elem << " ";
    return 0;
}