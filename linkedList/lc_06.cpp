/*
题目描述：
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false

示例 2:

输入: 1->2->2->1
输出: true

进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/


/*
解法：不需额外辅助空间，使用快慢指针来求解。慢指针一次走一步，快指针一次走两部，这样当快指针走到末尾的时候，慢指针处于中点，
不过要考虑下奇数和偶数的情况。链表的后半部分需要进行反转，然后快指针位于头部，慢指针位于尾部，同时向中点移动，当有对称点不
相等时，返回false。最后还要将反转后的链表恢复回来。
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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != NULL && fast->next->next != NULL){     //找中点
            slow = slow->next;
            fast = fast->next->next;
        }                                                                                                                                                                         fast = slow->next;     //指向链表后半部分的第一个节点
        slow->next = NULL;
        ListNode* tmp = NULL;
        while(fast != NULL){      //链表的后半部分反转
            tmp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = tmp;
        }
        tmp = slow;    //tmp为最后一个结点
        fast = head;
        bool res = true;
        while(fast != NULL && slow != NULL){
            if(fast->val != slow->val){
                res = false;
                break;
            }
            slow = slow->next;
            fast = fast->next;
        }
        slow = tmp->next;
        tmp->next = NULL;
        while(slow != NULL){
            fast = slow->next;
            slow->next = tmp;
            tmp = slow;
            slow = fast;
        }
        return res;
    }
};



/*
解法二：采用一个辅助栈来实现，need n extra space
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        stack<int> data;
        ListNode* l = head;
        while(l != NULL){
            data.push(l -> val);
            l = l -> next;
        }
        l = head;
        while(l != NULL){
            if(l->val != data.top())
                return false;
            l = l -> next;
            data.pop();
        }
        return true;
    }
};


