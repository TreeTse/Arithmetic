/*
题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，
返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/


//解法：设置两个指针pre和cur，pre指针指向当前确定不重复的结点，cur指针一直往后搜索；
//还要添加一个头节点，注意需要通过new ListNode(0)来创建，不然会出错(因为是创建一个
//新结点，所以要通过new分配空间)，新结点的下一个结点指向pHead，方便遇到第一、第二个
//结点重复的情况；


/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead){
        if(pHead == NULL || pHead->next == NULL)
            return pHead;
        ListNode* root = new ListNode(0);
        root->next = pHead;
        ListNode* pre = root;
        ListNode* cur = root->next;
        while(cur != NULL){
            if(cur->next != NULL && cur->val == cur->next->val){
                while(cur->next != NULL && cur->val == cur->next->val){
                    cur = cur->next;
                }
                pre->next = cur->next;
                cur->next = NULL;    //这部分可以要也可以不要
                cur = pre->next;
            }else{
                pre = pre->next;
                cur = cur->next;
            }
        }
        return root->next;
    }
};