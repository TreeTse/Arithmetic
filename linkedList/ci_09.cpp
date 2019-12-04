/*
题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
*/



//解法一：使用STL的set，只需遍历一遍就可判断出有没有环，还有环的入口地址
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
    ListNode* EntryNodeOfLoop(ListNode* pHead){
        set<ListNode*> s;
        ListNode* pNode = pHead;
        while(pNode != NULL){
            if(s.insert(pNode).second){
                pNode = pNode->next;
            }
            else
                return pNode;
        }
        return pNode;
    }
};


