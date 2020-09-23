/*
给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。
起止相连不算重叠。
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

int main(){
    // greedy strategy:
    // keep the next shorter and non-overlapping one in every step
    vector<vector<int>> intervals = {{1,2}, {2,3}, {3,4}, {1,3}};
    sort(intervals.begin(), intervals.end(), [] (vector<int> a, vector<int> b){
        return a[1] < b[1];
    });

    int ans = 0;
    int pre = intervals[0][1];
    for(int i = 1; i < intervals.size(); ++i){
        if(intervals[i][0] < pre){
            ++ans;
        }
        else{
            pre = intervals[i][1];
        }
    }
    cout << ans << endl;
    return 0;
}