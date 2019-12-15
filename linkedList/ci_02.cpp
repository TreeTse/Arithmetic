/*
题目描述：
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/



//解法：创建一个新的链表，当然这是在不考虑内存消耗的情况下，通过两个已知链表中元素的比较来排序，存进新的链表中。
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* head = new ListNode(0);
        ListNode* TempNode = NULL;
        if(pHead1 == NULL){
            return pHead2;
        }else if(pHead2 == NULL){
            return pHead1;
        }
        if(pHead1->val <= pHead2->val){
            head->next = pHead1;
            pHead1 = pHead1->next;
        }else{
            head->next = pHead2;
            pHead2 = pHead2->next;
        }
        TempNode = head->next;
        while(1){
            while(pHead1 != NULL && pHead1->val <= pHead2->val){
                TempNode->next = pHead1;
                TempNode = pHead1;
                pHead1 = pHead1->next;
            }
            if(pHead1 == NULL){
                break;
            }
            while(pHead2 != NULL && pHead2->val <= pHead1->val){
                TempNode->next = pHead2;
                TempNode = pHead2;
                pHead2 = pHead2->next;
            }
            if(pHead2 == NULL){
                break;
            }
        }
        if(pHead1 == NULL){
            TempNode->next = pHead2;
        }else{
            TempNode->next = pHead1;
        }
        return head->next;
    }
};


