#include<iostream>
using namespace std;
class mylinklist{
public:
    struct node{
        int val;
        node *next;
        node(int x):val(x),next(NULL){};
    };
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
private:
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
    list->deletenode(3);
    list->print_list();
    return 0;
}