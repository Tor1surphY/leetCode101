/*
给你一个字符串s，一个字符串t 。
请你设计一种算法，可以在O(n) 的时间复杂度内，从字符串s里面找出：
包含t所有字符的最小子串。
*/
#include <iostream>
#include <map>
#include <math.h>
#include <vector>
#include <string>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

bool check(map<char, int>& map_t, map<char, int>& map_s){
    for(auto p : map_t){
        if(p.second > map_s[p.first]) return false;
    }
    return true;
}


int main()
{
    // double pointer:
    // use left and right pointer to implement sliding window
    // count letters in t
    // count letters in s until it contains t
    // ++ left side
    //     check if new window contains t
    //         move left again
    //     else ++ right side
    // meanwhile keep the ans_window always smaller size
    string s = "ADOBECODEBANC";
    string t = "ABC";

    map<char, int> map_t, map_s;

    // count letters in t
    for(auto c : t) ++map_t[c];
    int fre_t = map_t.size();

    // move window until the end
    int cnt = 0, l = 0;
    int window_size = s.size()+1;
    int ans_l, ans_r;
    for(int r = 0; r < s.size(); ++r){
        ++map_s[s[r]];
        if(map_s[s[r]] == map_t[s[r]]){
            ++cnt;
            // if window contains t
            while(cnt == fre_t){
                if(r-l+1 < window_size){
                    ans_l = l;
                    ans_r = r;
                    window_size = r-l+1;
                }
                --map_s[s[l]];
                if(!check(map_t, map_s)) --cnt;
                ++l;
            }
        }
    }
    string ans;
    for(ans_l; ans_l <= ans_r; ++ans_l) ans += s[ans_l];
    cout << ans << endl;
    return 0;
}