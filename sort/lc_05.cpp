/*
题目描述：
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5
*/


/*
解法：使用归并排序。解决过程分为两部分：
一、使用快慢指针方法，寻找中点，并在中点位置切链表，一分为二；
二、排序合并链表的过程；可以使用递归形式来合并，非常简洁
*/


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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* pre = head, *slow = head, *fast = head;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        return mergeList(sortList(head), sortList(slow));
    }
    ListNode* mergeList(ListNode* left, ListNode* right) {
        if(!left) return right;
        if(!right) return left;
        if(left->val < right->val) {
            left->next = mergeList(left->next, right);
            return left;
        }
        else {
            right->next = mergeList(left, right->next);
            return right;
        }
    }
};
