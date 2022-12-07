/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-07 19:29:02
 * @LastEditTime : 2022-12-07 19:40:11
 ****************************************************************/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

void getNext1(int* next, const string& s){
    next[0] = -1;
    int k = -1;
    for(int j = 1;j < s.size(); j++){
        while(k >= 0 && s[j] != s[k + 1]) {
            k = next[k];
        }
        if(s[j] == s[k + 1]) {
            k++;
        }
        next[j] = k;
    }
}

void getNext2(int* next, const string& s)  
{  
    next[0] = -1;  
    int k = -1;  
    int j = 0;  
    while (j < s.size() - 1)  
    {  
        //p[k]表示前缀，p[j]表示后缀  
        if (k == -1 || s[j] == s[k])   
        {  
            ++k;  
            ++j;  
            next[j] = k;  
        }  else   
            k = next[k];  
    }  
}  

int main() {
    string s = "abac";
    int next1[s.size()];
    int next2[s.size()];
    getNext1(next1, s);
    getNext2(next2, s);

    for(int a : next1)
        cout << a << " ";
    cout << endl;
    for(int a : next2)
        cout << a << " ";
    cout << endl;
}