/*
n皇后问题研究的是如何将n个皇后放置在n×n的棋盘上
并且使皇后彼此之间不能相互攻击。

皇后彼此不能相互攻击，也就是说:
    任何两个皇后都不能处于同一条横行、纵行或斜线上。
*/
#include "../head.h"

void backTracking(vector<vector<string>>& ans, vector<string>& board,
                  vector<bool>& clm, vector<bool>& ldiag, vector<bool>& rdiag,
                  int row, int n) {
    if(row == n){
        ans.push_back(board);
        return;
    }
    for(int i = 0; i < n; ++i) {
        if (clm[i] || ldiag[n-row+i-1] || rdiag[row+i+1]) {
            continue;
        }
        // 修改当前节点状态
        board[row][i] = 'Q';
        clm[i] = ldiag[n-row+i-1] = rdiag[row+i+1] = true;
        // 递归子节点
        backTracking(ans, board, clm, ldiag, rdiag, row+1, n);
        // 回改当前节点状态
        board[row][i] = '.';
        clm[i] = ldiag[n-row+i-1] = rdiag[row+i+1] = false;
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    if(n == 0) return ans;
    vector<string> board(n, string(n, '.'));
    vector<bool> clm(n, false), ldiag(2*n-1, false), rdiag(2*n-1, false);
    backTracking(ans, board, clm, ldiag, rdiag, 0, n);
    return ans;
}

int main() {
    int n = 5;
    vector<vector<string>> ans = solveNQueens(n);
    rep(i, ans.size()) {
        rep(j, ans[0].size()) cout << ans[i][j] << endl;
        cout << endl;
    }
    return 0;
}