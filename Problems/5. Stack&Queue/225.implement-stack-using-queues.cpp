/****************************************************************
 * @file name    : File name
 * @Description  : Implement Stack by Queue.
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-08 13:14:39
 * @LastEditTime : 2022-12-08 14:28:04
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
private:
    queue<int> que;
public:
    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int size = que.size();
        size--;
        while(size--) {
            que.push(que.front());
            que.pop();
        }
        int result = que.front();
        que.pop();
        return result;
    }
    
    int top() {
        return que.back();
    }
    
    bool empty() {
        return que.empty(); 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

