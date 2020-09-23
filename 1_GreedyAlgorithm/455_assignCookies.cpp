/*
有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干都有一个大小。
每个孩子只能吃最多一个饼干，且只有饼干的大小大于孩子的饥饿度时，
这个孩子才能吃饱。
求解最多有多少孩子可以吃饱。
*/

#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i) 

int main(){
    // this algorithm need both vectors be sorted
    vector<int> kids = {1, 2, 3};
    vector<int> cookies = {3};
    int ans = 0;
    int j = 0;
    // every kid need the cookie that enough to feed 
    // and smallest one in current cookie vector
    rep(i, kids.size()){
        int tmp = kids[i];
        for(j; j < cookies.size(); ++j){
            if(cookies[j] >= tmp){
                ++ans;
                // when it is good to eat, remove from vector
                cookies.erase(cookies.begin());
                // goto next kid
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}