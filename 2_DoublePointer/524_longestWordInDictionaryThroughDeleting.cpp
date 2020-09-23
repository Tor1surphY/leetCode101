/*
给定一个字符串和一个字符串字典，找到字典里面最长的字符串
该字符串可以通过删除给定字符串的某些字符来得到。
如果答案不止一个，返回长度最长且字典顺序最小的字符串。
如果答案不存在，则返回空字符串。
*/
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

string minString(string& a, string& b){
    if(a < b) return a;
    else      return b;
}

int main(){
    // double pointer
    // one point to s, the other point to word in d
    // for each word in s, iterate over s and word at same time
    //     if(s[pointer1] == word[pointer2]) ++pointer1&2
    //     else ++pointer1
    // if s contains word, ans = word
    // return the longest and minimum dictionary order ans
    string s = "bab";
    vector<string> d = {"ba","ab","a"};
    
    string ans = "";
    int idx_s = 0, idx_d = 0;
    for(auto word : d){
        while(idx_d < word.size() && idx_s < s.size()){
            if(s[idx_s] == word[idx_d]) ++idx_d;
            ++idx_s;
        }
        if(idx_d == word.size()){
            if     (word.size() >  ans.size()) ans = word;
            else if(word.size() == ans.size()) ans = minString(ans, word);
        }
        idx_s = 0, idx_d = 0;
    }
    cout << ans << endl;
    return 0;
}