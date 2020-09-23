/*
给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
*/
#include "../head.h"



string frequencySort(string s){
    map<char, int> budget;
    for(char& cha : s) ++budget[cha];
    vector<pair<int, char>> ans(budget.size());
    int i = 0;
    for(auto& elem : budget){
        ans[i].first  = elem.second;
        ans[i].second = elem.first;
        ++i;
    }
    sort(ans.begin(), ans.end(), [] (pair<int, char> a, pair<int, char> b) {
        return a.first > b.first;
    });
    string ans_s = "";
    for(auto& elem : ans){
        for(int i = 0; i < elem.first; ++i) ans_s += elem.second;
    }
    return ans_s;
}

int main(){
    string s = "";
    cin >> s;
    cout << frequencySort(s) << endl;
    return 0;
}

/*
思路：
    map<char, int> budget(char, frq)
    vector<pair<int, char>> ans
    sort(ans)
    计数 -> 按频率排序 -> 输出
*/