/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start

#include <stack>
using namespace std;


class MyQueue {
public:
    stack<int> s1,s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        s2.push(x);
        
        stack<int> tmp = s2;
        while(!s1.empty()){
            s1.pop();
        }
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        s2 = tmp;
    }
    
    int pop() {
        int x = s1.top();
        s1.pop();
        stack<int> tmp = s1;
        while(!s2.empty()){
            s2.pop();
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1 = tmp;
        return x;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
        
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

