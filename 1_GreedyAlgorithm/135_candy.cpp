/*
一群孩子站成一排，每一个孩子有自己的评分。
现在需要给这些孩子发糖果，
规则是如果一个孩子的评分比自己身旁的一个孩子要高，
那么这个孩子就必须得到比身旁孩子更多的糖果；
所有孩子至少要有一个糖果。
求解最少需要多少个糖果。
*/

#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i) 

int main(){
    vector<int> ratings = {1, 0, 2};
    int n = ratings.size();
    vector<int> candies(n, 1);
    // greedy strategy:
    // 2 times loop, one from left to right
    //      compare right one to left one
    // the other from right to left
    //      compare left one to right one
    // make sure the bigger kid could get more candies in every step

    // right kid is better than me
    // so his candies must 1 bigger than mine
    for(int i = 1; i < n; ++i){
        if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1]+1;
    }

    // left kid is better than me
    // so his candies must 1 bigger than mine
    // but if he already has more candies
    // we don't need to add candies for him
    // we will add candies only when left kid is better than me
    // and his candies are not bigger than mine
    for(int i = n-1; i > 0; --i){
        if(ratings[i-1] > ratings[i]){
            if(candies[i-1] <= candies[i]) candies[i-1] = candies[i]+1;
        }
    }

    int ans = 0;
    rep(i, n) ans += candies[i];
    rep(i, n) cout << candies[i] << " ";
    cout << endl;
    cout << ans << endl;
    return 0;
}