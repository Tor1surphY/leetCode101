/*
假设有打乱顺序的一群人站成一个队列。
每个人由一个整数对(h, k)表示，
其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。
编写一个算法来重建这个队列。
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i) 

void Print(vector<vector<int>>& people){
    rep(i, people.size()){
        cout << "[" << people[i][0] << ", " << people[i][1] << "]" << endl;
    }
}

int main(){
    // greedy strategy:
    // 1. sort by h but if h is equal then sort by k
    //    to make sure every people in front of you is taller than you,
    //    and when your h is equal, the k of the those epeople in front of you
    //    always less than you
    // 2. for every people,
    //    keep the amount of the people who is taller than you
    //    in front of you equals to your k
    //    because of the people who in front of you all taller than you
    //    so you move your self after the k position
    //    it won't affect any people in front of you

    // 思路：
    //     按照降序排序，每一个在我前面的人都比我高，但是只能有k个人比我高
    //     所以我挪到第k个位置的后面，这样我前面就k个比我高的，并且我不影响后面人
    //     这样每次插入都在不影响别人的情况下又实现了自己的条件(局部最优解)
    // 注意：
    //     假设k没有按照升序排序，那么如果比较大的先插入，不会对前面造成影响
    //     但后面k小的数进行插入的时候，会插在前一个数的前面，结果上使前一个数的k加了1
    //     如果是k升序排序，那么无论什么情况前一个数永远在后一个数的前面，不会造成影响

    vector<vector<int>> people = {
        {9,0},{7,0},{1,9},{3,0},{2,7},{5,3},{6,0},{3,4},{6,2},{5,2}
    };

    sort(people.begin(), people.end(), [] (vector<int> a, vector<int> b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    });

    vector<int> tmp;
    int pos;

    for(int i = 0; i < people.size(); ++i){
        if(people[i][1] != i){
            tmp = people[i];
            pos = people[i][1];
            people.erase(people.begin()+i);
            people.insert(people.begin()+pos, tmp);
        }
    }
    Print(people);
    return 0;
}