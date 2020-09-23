/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
字符串只包含a-z。
*/
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

bool isPanlindrome(string s){
    int left = 0, right = s.size()-1;
    bool tag = 1;
    while(left < right){
        if(s[left] != s[right]){
            tag = 0;
            break;
        }
        ++left; --right;
    }
    return tag;
}

int main(){
    // double pointer
    // one from left, the other from right
    // every step valid s[left] == s[right]
    //     ++left --right
    // if not, 2 cases:
    //     erase left or right to get 2 new strings
    // valid 2 new strings
    // if one of them is panlindrome means s is panlindrome
    string s = "eceec";
    string a = s, b = s;

    int left = 0, right = s.size()-1;
    while(left < right){
        if(s[left] != s[right]){
            a.erase(a.begin()+left);
            b.erase(b.begin()+right);
            break;
        }
        ++left; --right;
    }

    cout << (isPanlindrome(a)||isPanlindrome(b)) << endl;
    return 0;
}