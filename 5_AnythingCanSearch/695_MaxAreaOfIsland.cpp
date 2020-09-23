/*
给定一个包含了一些0和1的非空二维数组grid
一个岛屿是由一些相邻的1(代表土地)构成的组合
这里的「相邻」要求两个1必须在水平或者竖直方向上相邻
你可以假设grid的四个边缘都被0（代表水）包围着

找到给定的二维数组中最大的岛屿面积
(如果没有岛屿，则返回面积为0)
*/
#include "../head.h"

#if 0
int dfs(vector<vector<int>>& grid, int x, int y){
    if(x < 0 || 
       y < 0 || 
       x >= grid.size() || 
       y >= grid.size() ||
       grid[x][y] == 0) return 0;

    grid[x][y] = 0;
    return 1 + dfs(grid, x+1, y) + dfs(grid, x-1, y)
             + dfs(grid, x, y-1) + dfs(grid, x, y+1);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int ans = 0;
    for(int y = 0; y < grid.size(); ++y){
        for(int x = 0; x < grid.size(); ++x){
            if(grid[x][y] == 1){
                ans = max(ans, dfs(grid, x, y)+1);
            }
        }
    }
    return ans;
}
#endif

#if 1
// 小技巧，当前坐标累加相邻的两位就是方向的变化
vector<int> drc{-1, 0, 1, 0, -1};

int maxAreaOfIsland(vector<vector<int>>& grid){
    int m = grid.size(), ans = 0, x, y;
    int n = m ? grid[0].size() : 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(grid[i][j]){
                int tmp = 1;
                grid[i][j] = 0;
                stack<pair<int, int>> island;
                island.push({i, j});
                while(!island.empty()){
                    pair<int, int> top = island.top();
                    island.pop();
                    for(int k = 0; k < 4; ++k){
                        x = top.first  + drc[k];
                        y = top.second + drc[k+1];
                        if(x >= 0 && x < m &&
                            y >= 0 && y < n && 
                            grid[x][y] == 1) {
                            grid[x][y] = 0;
                            ++tmp;
                            island.push({x, y});
                        }
                    }
                }
                ans = max(ans, tmp);
            }
        }
    }
    return ans;
}
#endif

int main(){
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    cout << maxAreaOfIsland(grid) << endl;
    return 0;
}
// 递归解法:
// 注意每个点的下标越界问题
// 注意递归的base case:
//     越界/等于0
// 和recursive case:
//     四个方向

// 栈解法:
// 用一个栈来存储每个为1的结点的子节点
//     遍历栈顶元素的四个方向，统计其中为1的结点的个数
//     如果为1，则压栈
//     四个方向都遍历结束，弹栈
// 直至栈空，则这个island的面积统计完成

// 注意搜索的本质，避免重复搜索
// 本题中把等于1的结点视为搜索过的结点而置0