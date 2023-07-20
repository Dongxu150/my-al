// 匿名结构体对象是一种临时对象，它在创建时不会被绑定到任何变量或指针上，因此它没有名称和地址。
// 在C++中，匿名对象是一种右值（rvalue），它们只能被用于表达式中，不能被取地址或绑定到引用上。

// 当创建一个匿名结构体对象时，它会被创建在栈上或者堆上的某个内存地址中，但这个地址是由编译器自动分配的，
// 程序员无法直接获取它的地址。因此，不能对匿名结构体对象使用取地址运算符&来获取其地址。

// 需要注意的是，在某些情况下，编译器可能会将匿名对象优化掉，以减少内存的开销。因此，在代码中
// 使用匿名对象时，应该避免将其地址传递给其他函数或者在其他地方持久地引用它。如果需要在其他地方
// 引用该对象，应该将它赋值给一个具名对象或者使用动态内存分配的方式（如new运算符）在堆上分配内存，
// 并将其地址赋值给指针变量。

#include<iostream>
using namespace std;
class myLinklist{
public:
    struct listnode{
        int val;
        listnode*next;
        listnode(int x):val(x),next(NULL){}
    };
    //初始化链表
    myLinklist():_size(0),_dummyhead(new listnode(0)){};
    // 获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
    int get (int index){
        if ((index<0)||(index>(_size-1))) {
            return -1;
        }
        listnode *cur = _dummyhead;
        while(index){
            //cur指向结构体，是个指向结构体的指针，拿next使用->
            cur = cur->next;
            index--;  
            }   
        return cur->next->val;
    }
    /// 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
    void  addathead(int val){
        //直接把你要输入的放进来，无需写待输入变量的类型
        listnode * newnode = new listnode(val);
        newnode->next = _dummyhead->next;
        _dummyhead->next = newnode;
        _size++;
    }
    // 在链表最后面添加一个节点
    
    void addtail(int val){
        listnode * newnode = new listnode(val);
        listnode*cur = _dummyhead->next;
        while(cur->next){
            cur = cur->next;

        }
        cout<<"加入尾部成功"<<endl;
        cur->next = newnode;
        _size++;
    }
    void add_index(int index,int val){
        if ((index<0) || (index>_size)){
            return;
        }
        listnode * newnode = new listnode(val);
        listnode * cur = _dummyhead;

        while(index){
            cur = cur->next;
            index--;
        }
        listnode *temp = cur->next;
        cur->next = newnode;
        newnode->next = temp;
        _size++;
        return ;
    cout<<"add_index_sucess"<<endl;
    }
    void printLinkedList() {
        listnode * cur = _dummyhead->next;
        while(cur){
            cout<<cur->val<<" ";
            cur = cur->next;
            //cout<<cur-val<<endl;
        }
    }
    void deleteAtIndex(int index) {
        if ((index<-1)||(index>_size)){
            return;
        }
        listnode * cur = _dummyhead;
        while(index){
            cur = cur->next;
            index--;

        listnode *temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        temp = NULL;
        _size--;


        }
    }
public:
    int _size;
    listnode *_dummyhead;
};

int main(){
    myLinklist * p = new myLinklist();

    p->addathead(1);
    p->addtail(2);
    p->add_index(1,5);
    p->add_index(0,0);
    p->printLinkedList();
    cout<<p->_size<<endl;

    return 0;
}
