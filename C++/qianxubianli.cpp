#include<iostream>
using namespace std;
struct treenode{
    int val;
    treenode * left;
    treenode * right;
    treenode(int x): val(x),left(NULL),right(NULL){};

};
//前序遍历函数
void qianxu(treenode *root){
    if (root==NULL){
        return;
    }
    cout<<root->val<<" ";
    qianxu(root->left);
    qianxu(root->right);
}
int main(){
    treenode * root = new treenode(0);
    root->left = new treenode(1);
    root->right = new treenode(2);
    root->left->left = new treenode(4);
    root->left->right = new treenode(5);
    cout << "前序遍历结果为：";
    qianxu(root);
    return 0;
}