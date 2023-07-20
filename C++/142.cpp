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
    //删除倒数第n个节点
    void delete_n(node * head,int n ){
        node *fast = head;
        node *slow = head;
        while(n){
            fast = fast->next;
            n--;
        }
        fast = fast->next;
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;


    }
    //找环形入点
    node* huanxing(node* head){
        
        //定义两个指针 快指针和慢指针
        node * slow = head;
        node * fast = head;
        
        while((fast)&&(fast->next)){

            fast = fast->next->next;
            slow = slow->next;
            if (slow==fast){
                node *index1 = fast;
                node *index2 = head;
                while(index1!=index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return NULL;



    }
public:
    int _size;
    node * _dummyhead;
};
int main(){
    mylinklist * list = new mylinklist();
    // for(int i=0;i<=5;i++){
    //     list->addnode(i);
    // }
    // list->addnode(6);
    // list->addnode(7);
    // list->addnode(8);
    node * node1 = new node(1);
    node * node2 = new node(2);
    node * node3 = new node(3);
    node * node4 = new node(4);
    node * node5 = new node(5);
    list->_dummyhead->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node3;
    //list->print_list();
    node* start = list->huanxing(list->_dummyhead->next);
    cout<<start->val<<endl;
    //cout<<node1->val;

    
    //list->print_list();
    // list->delete_n(list->_dummyhead->next,3);

  
    return 0;
}