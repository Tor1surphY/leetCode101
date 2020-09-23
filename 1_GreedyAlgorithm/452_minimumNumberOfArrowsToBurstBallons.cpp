/*
在二维空间中有许多球形的气球。
对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。
由于它是水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了。
开始坐标总是小于结束坐标。
平面内最多存在104个气球。
一支弓箭可以沿着x轴从不同点完全垂直地射出。
在坐标x处射出一支箭，若有一个气球的直径的开始和结束坐标为xstart，xend，
且满足xstart ≤ x ≤ xend，则该气球会被引爆。
可以射出的弓箭的数量没有限制。
弓箭一旦被射出之后，可以无限地前进。
我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

int main(){
    // greedy strategy:
    // find maximum overlapping intervals
    vector<vector<int>> points = {{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}};
    sort(points.begin(), points.end(), [] (vector<int> a, vector<int> b){
        return a[0] < b[0];
    });

    int ans = 1;
    vector<int> public_interval = points[0];
    for(int i = 1; i < points.size(); ++i){
        if(points[i][0] <= public_interval[1]){
            public_interval[0] = max(public_interval[0], points[i][0]);
            public_interval[1] = min(public_interval[1], points[i][1]);
        }
        else{
            ++ans;
            public_interval = points[i];
        }
    }
    cout << ans << endl;
    return 0;
}