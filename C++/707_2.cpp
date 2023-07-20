#include<iostream>
using namespace std;
//使用双向链表完成
class myLinklist{
public:
    
    struct node{
        int val;
        node *pre;
        node *next;
        node(int x):val(x),pre(NULL),next(NULL){};
    };
    //初始化
    myLinklist(){
        int _size = 0;
        this->_dummyhead = new node(0);
        this->_tailhead = new node(0);
        _dummyhead->next = _tailhead;
        _tailhead->pre = _dummyhead;
    };
    int get(int index) {
        if ((index<-1)||(index>_size)){
            return -1;
        }
        node *cur = _dummyhead;
        if (index<_size-index){
            while(index){
            index--;
            cur = cur->next;
        }
        
        }
        else{
            while(_size-index){
            index--;
            cur = cur->pre;
        }
        
        }
        return cur->val;
    }
    void addAtIndex(int index, int val) {
        if ((index<-1)||(index>_size)){
            return;
        }
        //先判断从左还是从右侧找，用cur找到待插入的位置，找cur和cur前一个节点进行插入
        node*cur = NULL;
        if (index<_size-index){
            cur =_dummyhead->next;
            while(index){
                cur = cur->next;
                index--;
            } 
        }
        else{
            cur = _tailhead;
            int j = _size-index;
            while(j){
                cur = cur->pre;
                j--;
            }
        }
        // 已经找到当前节点cur
        
        node * last = cur->pre;
        
        node* newnode = new node(val);
        last->next = newnode;
        cur->pre = newnode;
        newnode->next = cur;
        newnode->pre = last;
        _size++;
        //cout<<"添加成功"<<val<<endl;

    }
    void print_list(){
        node *cur = _dummyhead->next;
        while(cur!=_tailhead){
            cout<<cur->val<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
    void deleteindex(int index){
        if ((index<=0)||(index>=_size)){
            return;
        }
        else{
            cout<<"执行了"<<endl;
            node*cur = NULL;
            if (index<_size-index){
                cur = _dummyhead->next;
                while(index){
                    cur = cur->next;
                    index--;
                }
                cout<<cur->val<<endl;
            }
            else{
                cur = _tailhead;
                int j = _size-index;
                while(j){
                    cur = cur->pre;
                    j--;
                }
            //cout<<cur->val<<endl;
            }
            node *front = cur->pre;
            node *behind = cur->next;
            front->next = behind;
            behind->pre = front;
            delete cur;
            cur = NULL;
            _size--;

            }
        }
private:
    int _size;
    node * _dummyhead;
    node * _tailhead;

};
int main(){
    myLinklist *p = new class myLinklist();
    p->addAtIndex(0,1);
    p->addAtIndex(0,2);
    p->addAtIndex(0,3);
    p->addAtIndex(0,4);
    p->addAtIndex(0,5);
    p->addAtIndex(0,6);
    p->addAtIndex(5,7);
    p->print_list();
    p->deleteindex(2);
    p->print_list();
    return 0 ;
}