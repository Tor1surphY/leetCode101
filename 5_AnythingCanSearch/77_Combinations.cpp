/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
*/
#include "../head.h"

void backTracking(vector<vector<int>>& ans, vector<int>& cmb, int cnt, int lvl, int n, int k) {
    if(cnt == k) {
        ans.push_back(cmb);
        return;
    }
    for(int i = lvl; i <= n; ++i) {
        cmb[cnt++] = i;
        backTracking(ans, cmb, cnt, i+1, n, k);
        //  回溯发生在这里
        //  一次cmb填满后，返回，--cnt回溯
        --cnt;
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> cmb(k, 0);
    int cnt = 0;

    backTracking(ans, cmb, cnt, 1, n, k);
    return ans;
}

int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<vector<int>> ans = combine(n, k);
    rep(i, ans.size()) {
        rep(j, ans[0].size()) cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}