#include<iostream>
#include<queue>
using namespace std;
class mystack(){
public:
    queue<int> q1;
    queue<int> q2;

    mystack(){};
    void push(int x){
        q1.push(x);
    }
    int pop(){
        int size = q1.size();
        size--;
        while(size){
            q2.push(q1.front());
            q1.pop();
            size--;
        }
        int result = q1.front();
        q1.pop();
        q1 = q2;
        while(!q2.empty()){
            q2.pop();
        }
        //先把数据输入到队列1除了最后一个放到q2，把队列1最后一个pop出去，再把q2复制到q1
        return result
    }
    int top(){
        return q1.back();
    }
    bool empty(){
        return q1.empty;
    }

};
int main(){
    return 0;
}