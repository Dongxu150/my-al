#include <iostream>
#include <unordered_set>

using namespace std;

// 链表节点的定义
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 求解相交节点的函数
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    // 创建哈希表，用于存储第一个链表中的节点地址
    unordered_set<ListNode*> visited;

    // 遍历第一个链表，并将每个节点的地址存储在哈希表中
    ListNode* curr = headA;
    while (curr) {
        visited.insert(curr);
        curr = curr->next;
    }

    // 遍历第二个链表，对于每个节点，检查它是否已经存在于哈希表中
    curr = headB;
    while (curr) {
        if (visited.count(curr)) {
            return curr; // 如果找到了相交节点，则返回它的地址
        }
        curr = curr->next;
    }

    // 如果第二个链表遍历完毕仍未找到相交节点，则两个链表没有相交
    return NULL;
}

int main() {
    // 创建第一个链表
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);
    headA->next->next->next->next->next = new ListNode(6);

    // 创建第二个链表
    ListNode* headB = new ListNode(7);
    headB->next = new ListNode(8);
    headB->next->next = new ListNode(5);
    headB->next->next->next = new ListNode(7);

    // 将两个链表相交
    // 两个指针相等，可以理解为指向内存里同一块地址
    headA->next->next->next->next->next->next = headB->next->next;

    // 求解相交节点
    ListNode* intersection = getIntersectionNode(headA, headB);

    // 输出相交节点的值
    if (intersection) {
        cout << "The intersection node is " << intersection->val << endl;
    } else {
        cout << "The two lists do not intersect." << endl;
    }

    return 0;
}