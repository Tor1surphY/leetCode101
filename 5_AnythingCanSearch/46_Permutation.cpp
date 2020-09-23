/*
给定一个没有重复数字的序列，返回其所有可能的全排列。
*/
#include "../head.h"

void backTracking(vector<int>& nums, int lvl, vector<vector<int>>& ans) {
    // base case:
    // 当前搜素的深度达到数组长度时
    if(lvl == nums.size()-1) {
        ans.push_back(nums);
        return;
    }

    // 每一层循环都是针对当前层级后面元素的
    for(int i = lvl; i < nums.size(); ++i) {
        swap(nums[i], nums[lvl]);
        backTracking(nums, lvl+1, ans);
        // 真正的回溯发生在这一步
        // 即，上一个组合已经加入到答案中了
        //     那么操作会回到上一步
        swap(nums[i], nums[lvl]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    backTracking(nums, 0, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<vector<int>> ans = permute(nums);
    rep(i, ans.size()) {
        rep(j, ans[0].size()) cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}