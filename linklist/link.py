class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = None

    def add_at_head(self, val):
        node = ListNode(val)
        node.next = self.head
        self.head = node

    def add_at_tail(self, val):
        node = ListNode(val)
        if not self.head:
            self.head = node
        else:
            cur = self.head
            while cur.next:
                cur = cur.next
            cur.next = node

    def get(self, index):
        if index < 0:
            return -1
        cur = self.head
        for i in range(index):
            if not cur:
                return -1
            cur = cur.next
        if not cur:
            return -1
        return cur.val

    def delete_at_index(self, index):
        if index < 0:
            return
        if index == 0:
            self.head = self.head.next
            return
        cur = self.head
        for i in range(index - 1):
            if not cur:
                return
            cur = cur.next
        if not cur or not cur.next:
            return
        cur.next = cur.next.next

    def print_list(self):
        cur = self.head
        while cur:
            print(cur.val, end=' ')
            cur = cur.next
        print()

if __name__ == '__main__':
    # 创建链表
    llist = LinkedList()
    # 添加节点
    llist.add_at_head(1)
    llist.add_at_tail(2)
    llist.add_at_tail(3)
    llist.add_at_tail(4)
    # 打印链表
    llist.print_list()
    # 获取节点值
    print(llist.get(2))
    # 删除节点
    llist.delete_at_index(2)
    # 打印链表
    llist.print_list()