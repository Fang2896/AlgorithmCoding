#include<vector>
#include<unordered_set>
#include<iostream>

using namespace std;

// 用来分解一个数的digits
vector<int> digitSep(int n) {
    vector<int> digits;
    int temp;
    while(n != 0) {
        temp = n % 10;
        digits.emplace_back(temp);
        n = n / 10;
    }
    return digits;
}
int sumOfSquare(vector<int> vec) {
    int sumS = 0;
    for(int num : vec) {
        sumS += num*num;
    }
    return sumS;
}

bool isHappy(int n) {
        // 先解决一个问题，如何拆分一个数的各个位
    unordered_set<int> mp;   // 用来存储出现过的sumS
    vector<int> temp = digitSep(n);
    int sumS = sumOfSquare(temp);
    // 跳出循环的俩条件：1. sumS=1，2. 发现重复数字！
    while(sumS != 1 && mp.find(sumS) == mp.cend()) {
        mp.insert(sumS);
        temp = digitSep(sumS);
        sumS = sumOfSquare(temp);
    }
    if(sumS == 1)
        return true;
    else
        return false;
}

int main() {
    int n = 2;
    vector<int> digits = digitSep(n);
    for(auto i : digits)
        cout << i << ' ';
    cout << endl;
    bool ans = isHappy(n);
    cout << ans << endl;

    return 0;
}
