/*
题目描述
输入一个链表，反转链表后，输出新链表的表头。
*/

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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* cur = pHead;
        ListNode* pnext = NULL;
        ListNode* pre = NULL;
        while(cur != NULL){
            pnext = cur->next;
            cur->next = pre;
            pre = cur;
            cur = pnext;
        }
        return pre;
    }
};
/*
定义三个指针，cur始终指向正在考察的节点，
pre始终指向已反序的最后一个节点
pnext指向待反序的第一个节点
*/

