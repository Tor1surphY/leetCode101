/*
给定一个m*n的非负整数矩阵来表示一片大陆上各个单元格的高度。
“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。
规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。
请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。

提示：
输出坐标的顺序不重要
m和n都小于150
*/
#include "../head.h"

vector<int> direction{-1, 0, 1, 0, -1};

void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& sea, int x, int y) {
    if(sea[x][y]) { return; }
    sea[x][y] = 1;
    int _x, _y;
    for(int i = 0; i < 4; ++i) {
        // 同695一样的小技巧
        _x = x + direction[i];
        _y = y + direction[i+1];
        // 目标点必须比当前点海拔高， 且
        // 不能超出范围
        if(_x >= 0 && _x < matrix.size() &&
           _y >= 0 && _y < matrix[0].size() &&
           matrix[x][y] <= matrix[_x][_y]) {
               dfs(matrix, sea, _x, _y);
           }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    if(matrix.empty() || matrix[0].empty()) { return {}; }
    int m = matrix.size(), n = matrix[0].size();

    vector<vector<bool>> pcf(m, vector<bool> (n, 0));
    vector<vector<bool>> atl(m, vector<bool> (n, 0));

    // 得出可以到达两个大洋的两个矩阵
    for(int i = 0; i < m; ++i) {
        dfs(matrix, pcf, i, 0);
        dfs(matrix, atl, i, n-1);
    }
    for(int i = 0; i < n; ++i) {
        dfs(matrix, pcf, 0,   i);
        dfs(matrix, atl, m-1, i);
    }

    vector<vector<int>> ans;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(pcf[i][j] && atl[i][j]) {
                ans.push_back(vector<int> {i, j});
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5}, 
        {5, 1, 1, 2, 4}
    };
    vector<vector<int>> ans = pacificAtlantic(matrix);
    rep(i, ans.size()) {
        cout << "(" << ans[i][0] << ", " << ans[i][1] << ") ";
    }
    cout << endl;
    return 0;
}

/*
如果逐一搜素的话，最差情况下时间复杂度可能为O(N^3)
使用逆向思维；
    从四条边向内搜素，因此只需要搜素四条边上的点
    设置两个vector对应两个大洋，可以到达的标1
    最终遍历两个vector，重合的就是答案
    * 空间复杂度较大
*/