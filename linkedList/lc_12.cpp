/*
题目描述：
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/


//解法：使用双指针，沿着链表依次比较、重连

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode;
        ListNode* p = res;
        while(l1 != NULL && l2 != NULL){
            if(l1->val >= l2->val){
                p->next = l2;
                l2 = l2->next;
            }
            else{
                p->next = l1;
                l1 = l1->next;
            }
            p = p->next;
        }
        if(l1 == NULL){
            p->next = l2;
        }
        else{
            p->next = l1;
        }
        return res->next;
    }
};