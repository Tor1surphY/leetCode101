/*
给定两个单词（beginWord和endWord）和一个字典wordList
找出所有从beginWord到endWord的最短转换序列。

转换需遵循如下规则：
    每次转换只能改变一个字母。
    转换后得到的单词必须是字典中的单词。

说明:
    如果不存在这样的转换序列，返回一个空列表。
    所有单词具有相同的长度。
    所有单词只由小写字母组成。
    字典中不存在重复的单词。
    你可以假设beginWord和endWord是非空的，且二者不相同。
*/
#include "../head.h"

void backtracking(const string &src, const string &dst, 
                  unordered_map<string, vector<string>> &next, 
                  vector<string> &path, vector<vector<string>> &ans) {
    if(src == dst) {
        ans.push_back(path);
        return;
    }
    for(const auto &s : next[src]) {
        path.push_back(s);
        backtracking(s, dst, next, path, ans);
        path.pop_back();
    }
}

vector<vector<string>> findLadders(string begin_word, string end_word,
                                   vector<string> &word_list) {
    vector<vector<string>> ans;
    unordered_set<string> dict;
    for(const auto &w : word_list) dict.insert(w);
    if(!dict.count(end_word)) return ans;
    dict.erase(begin_word);
    dict.erase(end_word);
    unordered_set<string> q1{begin_word}, q2{end_word};
    unordered_map<string, vector<string>> next;
    bool reversed = false, found = false;

    while(!q1.empty()) {
        unordered_set<string> q;
        for (const auto &w : q1) {
            string s = w;
            for (size_t i = 0; i < s.size(); i++) {
                char ch = s[i];
                for (int j = 0; j < 26; j++) {
                    s[i] = j + 'a';
                    if (q2.count(s)) {
                        reversed ? next[s].push_back(w) : next[w].push_back(s);
                        found = true;
                    }
                    if (dict.count(s)) {
                        reversed ? next[s].push_back(w) : next[w].push_back(s);
                        q.insert(s);
                    }
                }
                s[i] = ch;
            }
        }
        if(found) break;
        for(const auto &w : q) dict.erase(w);
        if(q.size() <= q2.size()) q1 = q;
        else {
            reversed = !reversed;
            q1 = q2;
            q2 = q;
        }
    }
    if(found) {
        vector<string> path = {begin_word};
        backtracking(begin_word, end_word, next, path, ans);
    }
    return ans;
}

int main() {
    string begin_word = "hit";
    string end_word = "cog";
    vector<string> word_list = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> ans = findLadders(begin_word, end_word, word_list);
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans[0].size(); ++j)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}