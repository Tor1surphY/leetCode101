/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。
单词必须按照字母顺序，通过相邻的单元格内的字母构成
其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用。
*/
#include "../head.h"

void backTracking(int i, int j, string& word, bool& is_found, int lvl,
                  vector<vector<char>>& board, vector<vector<bool>>& is_visited) {
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
    if(is_visited[i][j] || is_found || board[i][j] != word[lvl]) return;
    if(lvl == word.size()-1) {
        is_found = 1;
        return;
    }
    //  核心思路就是，从不管矩阵的哪一个点出发，符合当前匹配位置的点会被标记1
    //  但如果这个点出发的其他方向没有一个符合要求，那么这个点的方向也是走不通的
    //  所以就需要**回溯**到这个点之前的点，再继续对剩下的几个方向进行相同模式的查找
    //  感觉回溯法有一些“顺序匹配”的感觉，如果遇到不匹配的部分就回溯，再去别的方向寻找
    is_visited[i][j] = 1;
    backTracking(i+1, j,   word, is_found, lvl+1, board, is_visited);
    backTracking(i-1, j,   word, is_found, lvl+1, board, is_visited);
    backTracking(i,   j+1, word, is_found, lvl+1, board, is_visited);
    backTracking(i,   j-1, word, is_found, lvl+1, board, is_visited);
    is_visited[i][j] = 0;
}

bool exist(vector<vector<char>>& board, string word) {
    if(board.empty()) return 0;

    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> is_visited(m, vector<bool> (n, 0));
    bool is_found = 0;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            backTracking(i, j, word, is_found, 0, board, is_visited);
        }
    }
    return is_found;
}

int main() {
    vector<vector<char>> board;
    string word;
    cout << exist(board, word) << endl;
    return 0;
}