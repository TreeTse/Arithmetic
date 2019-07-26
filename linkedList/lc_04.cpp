/*
题目描述：
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.

说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
*/

//解法：设置双指针p1和p2，让他们之间相隔的元素个数为2，当p2指向链表末尾的NULL时，删除掉p1的下一个指针结点

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */ 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        
        ListNode* p1 = dummy;
        ListNode* p2 = dummy;
        int k = n+1;
        while(k != 0){
            p2 = p2 -> next;
            k--;
        }
        while(p2 != NULL){
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        p1 -> next = p1 -> next -> next;
        ListNode* reNode = dummy -> next;
        delete dummy;
        
        return reNode;
    }
};

