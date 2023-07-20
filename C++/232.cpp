#include <stack>
#include <cassert>
#include<iostream>
using namespace std;

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;

    MyQueue() {}

    void push(int x) {
        stIn.push(x);
    }

    int pop() {
        if (stOut.empty()) {
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    int peek() {
        int res = this->pop();
        stOut.push(res);
        return res;
    }

    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

int main() {
    MyQueue q;

    // 添加元素并验证队列是否为空
    q.push(1);
    assert(!q.empty());

    // 添加更多元素并验证队列大小
    q.push(2);
    q.push(3);
    assert(q.stIn.size() == 3);

    // 弹出元素并验证元素顺序
    assert(q.pop() == 1);
    assert(q.pop() == 2);
    assert(q.pop() == 3);

    // 验证队列是否为空
    assert(q.empty());

    // 添加元素并验证 peek 函数是否返回正确元素
    q.push(4);
    assert(q.peek() == 4);

    // 再次验证队列是否为空
    assert(!q.empty());

    // 弹出元素并验证队列是否为空
    q.pop();
    assert(q.empty());

    return 0;
}