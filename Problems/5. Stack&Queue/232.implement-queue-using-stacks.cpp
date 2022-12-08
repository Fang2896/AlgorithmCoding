/****************************************************************
 * @file name    : File name
 * @Description  : Implement Queue by Stack
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-08 13:14:09
 * @LastEditTime : 2022-12-08 14:10:06
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
private:
    stack<int> InStack;
    stack<int> OutStack;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        InStack.push(x);
    }
    
    int pop() {
        // 只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
        if(OutStack.empty()) {
            while(!InStack.empty()) {
                OutStack.push(InStack.top());
                InStack.pop();
            }
        }
        int result = OutStack.top();
        OutStack.pop();
        return result;
    }
    
    int peek() {
        int res = this->pop();
        OutStack.push(res);
        return res;
    }
    
    bool empty() {
        return InStack.empty() && OutStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

