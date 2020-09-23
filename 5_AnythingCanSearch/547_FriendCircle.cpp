/*
班上有N名学生。其中有些人是朋友，有些则不是。
他们的友谊具有是传递性。
如果已知A是B的朋友，B是C的朋友，那么我们可以认为A也是C的朋友。
所谓的朋友圈，是指所有朋友的集合。

给定一个N*N的矩阵M，表示班级中学生之间的朋友关系。
如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。
你必须输出所有学生中的已知的朋友圈总数。
*/
#include "../head.h"

void dfs(vector<vector<int>>& M, int i, vector<bool>& is_visited) {
    // 被访问了，置为1
    is_visited[i] = 1;
    // 对于第i个同学，查看他所在行里有几个1
    // 即，有几个朋友
    // 只要这个朋友还没有被访问过，那么他就会被加入当前的朋友圈
    // 直至这个同学的所有递归的朋友都被访问完
    for(int k = 0; k < M.size(); ++k) {
        if(M[i][k] == 1 && !is_visited[k]) {
            dfs(M, k, is_visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& M) {
    int m = M.size(), ans = 0;
    vector<bool> is_visited(m, 0);
    // 纵轴m个同学，is_visited代表纵轴每个同学是否被访问干净
    for(int i = 0; i < m; ++i) {
        // 如果没被访问，就去递归访问他的所有朋友
        if(!is_visited[i]) {
            dfs(M, i, is_visited);
            ++ans;
        }
    }
    return ans;
}

#if 1
// 这道题也可以用并查集来解
class UnionFind {
public:
    UnionFind(int n)
    : friends(vector<int> (n, -1))
    , cnt(n) {}

    // 路径压缩
    int findRoot(int x) {
        if(friends[x] < 0) return x;
        else               return findRoot(friends[x]);
    }

    void unite(int i, int j) {
        i = findRoot(i);
        j = findRoot(j);
        if(i != j){
            friends[j] = i;
            --cnt;
        }
    }

    int getCnt() { return cnt; }

private:
    int cnt;
    vector<int> friends;
};

int testUnionFind(vector<vector<int>>& M) {
    int n = M.size();
    UnionFind uf(n);
    for(int i = 0; i < n-1; ++i) {
        for(int j = i+1; j < n; ++j) {
            if(M[i][j] == 1) uf.unite(i, j);
        }
    }
    return uf.getCnt();
}

#endif

int main() {
    vector<vector<int>> M = {
        {1, 1,0,0,0,0,0,1,0,0,0,0,0,0,0},
        {1,1, 0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1, 0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1, 0,1,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,1, 0,0,0,0,1,1,0,0,0,0},
        {0,0,0,1,0,1, 0,0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,1, 0,1,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,1, 1,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,1,1, 0,0,0,0,1,0},
        {0,0,0,0,1,0,0,0,0,1, 0,1,0,0,1},
        {0,0,0,0,1,1,0,0,0,0,1, 1,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,1,1, 0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1, 0,0},
        {0,0,0,0,0,0,1,0,1,0,0,0,0,1, 0},
        {0,0,0,0,0,0,0,0,0,1,0,0,0,0,1 } 
    };
    // cout << findCircleNum(M) << endl;
    cout << testUnionFind(M) << endl;
    return 0;
}
