/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。
你可以尽可能地完成更多的交易（多次买卖一支股票）。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/

#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i) 

int main(){
    // greedy strategy:
    // get every upgrow day set
    vector<int> prices = {1};
    if(1 == prices.size()){
        cout << 0 << endl;
        return 0;
    }
    int low, high;
    low = prices[0];
    high = prices[0];
    int ans = 0;
    for(int i = 1; i < prices.size(); ++i){
        if(prices[i] < prices[i-1]){
            ans += high - low;
            low = prices[i];
            high = prices[i];
        }
        else{
            high = prices[i];
        }
    }
    ans += high - low;
    cout << ans << endl;
    return 0;
}