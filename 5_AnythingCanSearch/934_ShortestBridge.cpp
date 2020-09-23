/*
在给定的二维二进制数组A中，存在两座岛
岛是由四面相连的1形成的一个最大组。
现在，我们可以将0变为1，以使两座岛连接起来，变成一座岛。
返回必须翻转的0的最小数目。
可以保证答案至少是1。
*/
#include "../head.h"

vector<int> drc = {-1, 0, 1, 0, -1};

void dfs(vector<vector<int>>& A, queue<pair<int, int>>& q, int m, int n, int i, int j) {
    if(i < 0 || j < 0 || i >= m || j >= n || A[i][j] == 2) return;
    if(A[i][j] == 0) return;

    //  when found 1, get target.
    A[i][j] = 2;
    q.push({i, j});
    dfs(A, q, m, n, i-1, j);
    dfs(A, q, m, n, i+1, j);
    dfs(A, q, m, n, i,   j-1);
    dfs(A, q, m, n, i,   j+1);
}

//  实际上是在求两个岛屿之间的最短距离
int shortestBridge(vector<vector<int>>& A) {
    int m = A.size(), n = A[0].size();
    //  q has all the first island's point
    queue<pair<int, int>> q;
    bool flipped = 0;

    //  use dfs to search the first island
    //  and tag them as 2
    for(int i = 0; i < m; ++i) {
        if(flipped) break;
        for(int j = 0; j < n; ++j) {
            if(A[i][j] == 1) {
                dfs(A, q, m, n, i, j);
                flipped = 1;
                break;
            }
        }
    }

    //  use bfs to search second island
    //  so when reach the second island, the depth is the answer
    int x, y;
    int lvl = 0;
    while(!q.empty()) {
        int sz_q = q.size();
        while(sz_q--) {
            //  pop queue get a point in first island
            auto tmp = q.front();
            q.pop();
            //  bfs, seach 4 drections
            for(int k = 0; k < 4; ++k) {
                x = tmp.first +  drc[k];
                y = tmp.second + drc[k+1];
                if(x >= 0 && y >= 0 && x < m && y < n) {
                    //  already searched / this is another point in first island
                    if(A[x][y] == 2) continue;
                    //  find the target second island
                    if(A[x][y] == 1) return lvl;
                    //  if reach 0, flipped to 2 and push in queue
                    q.push({x, y});
                    A[x][y] = 2;
                }
            }
        }
        ++lvl;
    }
    return 0;
}

int main() {
    vector<vector<int>> A = {
        {0, 1},
        {1, 0}
    };
    int ans = shortestBridge(A);
    cout << ans << endl;
    return 0;
}