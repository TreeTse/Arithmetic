/*
题目描述：
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。
*/

//解法：将小于特定值的节点分到一个新的链表中，将大于等于特定值的节点分到另一个新的链表中，
//然后合并链表



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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(0);
        ListNode* les = dummy1;
        ListNode* gre = dummy2;
        ListNode* cur = head;
        while(cur != NULL){
            if(cur -> val < x){
                les -> next = cur;
                cur = cur -> next;
                les = les -> next;
                les -> next = NULL;
            }else{
                gre -> next = cur;
                cur = cur -> next;
                gre = gre -> next;
                gre -> next = NULL;
            }
        }
        les -> next = dummy2 -> next;
        ListNode* ret = dummy1 -> next;
        delete dummy1;
        delete dummy2;
        return ret;
    }
};

