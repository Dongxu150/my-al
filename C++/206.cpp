#include<iostream>
using namespace std;
struct node{
        int val;
        node *next;
        node(int x):val(x),next(NULL){};
    };
class mylinklist{
public:
    
    mylinklist(){
        int _size = 0;
        this->_dummyhead = new node(0);


    };
    void deletenode(int val){
        node *cur = _dummyhead;
        while(cur->next){
            if (cur->next->val ==val){
                cur->next = cur->next->next;
                _size--;
            }
            else{
                cur = cur->next;
            }
        }
    }
    void addnode(int val){
        node*p = new node(val);
        node *cur = _dummyhead;
        while(cur->next){
            cur = cur->next;
        }
        cur->next = p;
        _size++;

    }
    void print_list(){
        node *cur = _dummyhead->next;
        while(cur){
            cout<<cur->val<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
    void reverse(){
        
    }
    //反转链表使用递归法
    node* reverse(node*  head){
        if (head==NULL||head->next==NULL){
            return head;
        }
        node *cur = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return cur;

    }    
    //反转链表头差法
    node * touchafa(node*head){
        node * cur = new node(0);
        while(head){
            node * temp = head->next;
            head->next = cur;
            cur = head;
            head = temp;

        }
        cout<<"sucess"<<endl;
        cout<<cur->val<<endl;
        return cur;
    }
public:
    int _size;
    node * _dummyhead;
};
int main(){
    mylinklist * list = new mylinklist();
    for(int i=0;i<=5;i++){
        list->addnode(i);
    }
    list->addnode(3);
    list->addnode(3);
    list->addnode(3);
    
    list->print_list();

    // node*newnode = list->reverse(list->_dummyhead->next);
    // cout<<newnode->next->val<<endl;
    // while(newnode){
    //     cout<<newnode->val<<" ";
    //     newnode = newnode->next;
    // }
    node*newnode = list->touchafa(list->_dummyhead->next);
    //cout<<newnode->val<<endl;
    while(newnode){
        cout<<newnode->val<<" ";
        newnode = newnode->next;
    }
    return 0;
}