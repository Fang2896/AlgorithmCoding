/*************************************
 * @file name: File name
 * @Description: 
 * @Version: 0.0
 * @Author: M1kanN
 * @Date: 2022-12-06 16:28:46
 * @LastEditTime: 2022-12-06 16:56:02
 *************************************/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    /*************************************
     * @Funticon name: Please write your function name here
     * @Berif: Briefly describe the function of your function
     * @Author: M1kanN
     * @Data: Do not edit
     * @Note: Need note condition
     *************************************/
    string replaceSpace(string) {
        // 先扩充数组到替换后的大小！
        // 然后用双指针法从后往前替换
        int count = 0;
        int sOldSize = s.size();
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ')
                count++;
        }
        s.resize(s.size() + count * 2);
        int sNewSize = s.size();
        for(int i = sNewSize - 1, j = s.sOldSize - 1; j < i; i--, j--) {
            if(s[j] != ' ') 
                s[i] = s[j];
            else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};

int main() {
    return 0;
}  