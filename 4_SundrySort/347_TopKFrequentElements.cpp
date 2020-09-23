/*
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
要求：时间复杂度 **优于** O(NlogN)
即、
*/

#include "../head.h"

vector<int> topKFrequent(vector<int>& nums, int k){
    // frq用来统计每个数出现的频率
    // 如果是AtCoder的话这里习惯用数组统计，但是比较占空间，C++的话尽量用map
    map<int, int> frq;
    // cnt用来记录最高频率
    int cnt = 0;
    for(auto& x : nums) cnt = max(cnt, ++frq[x]);
    // budget里的vector用来统计当前频率下的元素有哪些
    // budget本身的下标就是频率，所以budget的空间是cnt
    //     方便统计，保证下标统一，所以是cnt+1
    vector<vector<int>> budget(cnt+1);
    // 给每个budget元素push符合他当前频率的nums中的元素
    for(auto& x : frq) budget[x.second].push_back(x.first);

    // 把频率前k个输出到ans
    vector<int> ans;
    for(int i = cnt; i >= 0 && ans.size() < k; --i){
        for(auto& x : budget[i]) ans.push_back(x);
        if(ans.size() == k) break;
    }
    return ans;
}

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    int k = 0;
    cin >> k;
    vector<int> ans = topKFrequent(nums, k);
    rep(i, ans.size()) cout << ans[i] << " ";
    cout << endl;
    return 0;
}

// 该方法的时间复杂度为O(N)