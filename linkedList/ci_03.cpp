/*
题目描述：输入两个链表，找出它们的第一个公共结点。
*/

//解法1：使用求差法

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
int getLength(ListNode* pHead){
    int count = 0;
    if(pHead == NULL)
        return 0;
    ListNode* tmp = pHead;
    while(tmp){
        tmp = tmp->next;
        count++;
    }
    return count;
}
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1 = getLength(pHead1);
        int len2 = getLength(pHead2);
        int dif = len1 - len2;
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        ListNode* FirstCom = NULL;
        if(dif > 0){
            for(int i = 0; i < dif; i++){
                cur1 = cur1->next;
            }
        }
        else {
            for(int i = dif; i != 0; i++){
                cur2 = cur2->next;
            }
        }
        while(cur1 != NULL && cur2 != NULL){
            if(cur1->val == cur2->val){
                FirstCom = cur1;
                break;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return FirstCom;
    }
};

