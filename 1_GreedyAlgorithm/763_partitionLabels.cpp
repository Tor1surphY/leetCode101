/*
字符串S由小写字母组成。
我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。
返回一个表示每个字符串片段的长度的列表。
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

int main(){
    // greedy strategy:
    // partition every new letter's intervals
    string S = "eccbbbbdec";

// pre process
    vector<vector<int>> data(26);
    vector<char> alp = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z'
    };
    int cnt = 0, tag = 0;
    // count each position for every letter
    for(int i = 0; i < 26; ++i){
        for(int j = 0; j < S.size(); ++j){
            if(S[j] == alp[i]){
                ++cnt;
                data[i].push_back(j);
            }
        }
        if(cnt) ++tag;
        cnt = 0;
    }
    vector<vector<int>> ans(tag);
    // record the begin and end position for every letter
    int j = 0;
    for(int i = 0; i < 26; ++i){
        if(!data[i].empty()){
            ans[j].push_back(data[i][0]);
            ans[j].push_back(data[i][data[i].size()-1]);
            ++j;
        }
    }
    // sort by their begin position
    sort(ans.begin(), ans.end(), [] (vector<int> a, vector<int> b){
        return a[0] < b[0];
    });
// end of pre process

    vector<int> rsl;
    int begin, end;
    begin = ans[0][0];
    end = ans[0][1];
    // if 2 letter have overlapping intervals
    // they should be set in one intervals
    // if not, make it a new interveal
    for(int i = 1; i < ans.size(); ++i){
        if(ans[i][0] < end){
            begin = min(ans[i][0], begin);
            end = max(ans[i][1], end);
        }
        else{
            rsl.push_back(end-begin+1);
            begin = ans[i][0];
            end = ans[i][1];
        }
    }
    rsl.push_back(end-begin+1);
    rep(i, rsl.size()) cout << rsl[i] << " ";
    cout << endl;
    return 0;
}