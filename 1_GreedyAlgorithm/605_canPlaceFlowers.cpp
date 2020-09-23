/*
假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。
可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。
能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

int main(){
    // greedy strategy:
    // every 0 has 0 on its both sides is a can-placed-bed
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 2;
    int size = flowerbed.size();
    int ans = 0;

    if(flowerbed[0] == 0 && flowerbed[1] == 0){
        flowerbed[0] = 1;
        ++ans;
    }
    if(flowerbed[size-1] == 0 && flowerbed[size-2] == 0){
        flowerbed[size-1] = 1;
        ++ans;
    }

    for(int i = 1; i < size-1; ++i){
        if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
            flowerbed[i] == 1;
            ++ans;
        }
    }
    cout << n << endl;
    cout << ans << endl;
    return 0;
}